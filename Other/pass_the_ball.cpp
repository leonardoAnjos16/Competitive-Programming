#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const int MAX = 1 << 22;
const ldouble PI = acosl(-1);

struct Complex {
	ldouble real, imag;

	Complex(ldouble real = 0.0L, ldouble imag = 0.0L): real(real), imag(imag) {}

	Complex conj() {
        return Complex(real, -imag);
    }

    Complex operator +(Complex const &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator -(Complex const &other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator *(Complex const &other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + other.real * imag);
    }

    Complex operator /(ldouble k) const {
        return Complex(real / k, imag / k);
    }

    Complex& operator *=(Complex other) {
        return *this = *this * other;
    }

    Complex& operator /=(ldouble k) {
        real /= k;
        imag /= k;
        return *this;
    }
};

int bits[MAX];
Complex root[MAX];

void get_roots() {
	root[1] = Complex(1);
	for (int len = 2; len < MAX; len += len) {
		Complex z(cos(PI / len), sin(PI / len));
		for (int i = len / 2; i < len; i++) {
			root[2 * i] = root[i];
			root[2 * i + 1] = root[i] * z;
		}
	}
}

void get_bits(int n) {
	int LOG = 0;
    while ((1 << (LOG + 1)) < n) LOG++;

    for (int i = 1; i < n; i++)
        bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
}

vector<Complex> FFT(vector<Complex> a, bool inv = false) {
    int n = a.size();
    get_bits(n);

    if (inv) reverse(a.begin() + 1, a.end());

    for (int i = 0; i < n; i++) {
        int to = bits[i];
        if (to > i) swap(a[to], a[i]);
    }

    for (int len = 1; len < n; len += len)
        for (int i = 0; i < n; i += 2 * len)
            for (int j = 0; j < len; j++) {
                Complex u = a[i + j], v = a[i + j + len] * root[len + j];
                a[i + j] = u + v;
                a[i + j + len] = u - v;
            }

    if (inv)
        for (int i = 0; i < n; i++)
            a[i] /= n;

    return a;
}

template<typename T, typename U>
vector<T> convolution(vector<U> const &a, vector<U> const &b) {
    int na = a.size(), nb = b.size(), n = 1;
    while (n <= na + nb - 2) n += n;

    vector<Complex> P(n);
    for (int i = 0; i < n; i++) {
        if (i < na) P[i].real = a[i];
        if (i < nb) P[i].imag = b[i];
    }

    P = FFT(P);
    for (int i = 0; i < n; i++)
        P[i] *= P[i];

    P = FFT(P, true);

    vector<T> c(n);
    for (int i = 0; i < n; i++)
        c[i] = (T) (P[i].imag / 2 + 0.5L);

    while (!c.empty() && !c.back())
        c.pop_back();

    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    get_roots();

    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<bool> vis(n, false);
    vector<vector<int>> cycles;

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        int idx = i;
        vector<int> cycle;

        while (!vis[idx]) {
            vis[idx] = true;
            cycle.push_back(idx + 1);
            idx = p[idx];
        }

        cycles.push_back(cycle);
    }

    vector<vector<llong>> sums;
    for (vector<int> cycle: cycles) {
        vector<int> rev = cycle;
        reverse(rev.begin(), rev.end());

        int sz = cycle.size();
        vector<llong> sum(sz);
        vector<llong> conv = convolution<llong, int>(cycle, rev);

        sum[0] = conv[sz - 1];
        for (int i = 1; i < sz; i++) {
            sum[i] = conv[i - 1] + conv[sz + i - 1];
        }

        sums.push_back(sum);
    }

    vector<int> sizes;
    vector<vector<llong>> cumulated_sums(n + 1);

    for (vector<llong> sum: sums) {
        int sz = sum.size();
        sizes.push_back(sz);

        if (cumulated_sums[sz].empty()) cumulated_sums[sz] = sum;
        else {
            for (int i = 0; i < sz; i++)
                cumulated_sums[sz][i] += sum[i];
        }
    }

    sort(sizes.begin(), sizes.end());
    sizes.erase(unique(sizes.begin(), sizes.end()), sizes.end());

    while (q--) {
        int k; cin >> k;

        llong ans = 0LL;
        for (int sz: sizes)
            ans += cumulated_sums[sz][k % sz];

        cout << ans << "\n";
    }
}