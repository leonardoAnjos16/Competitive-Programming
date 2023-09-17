#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Complex complex<double>

void FFT(vector<Complex> &a) {
	static vector<Complex> rt(2, 1);
	static vector<complex<ldouble>> R(2, 1);
	int n = a.size(), L = 31 - __builtin_clz(n);

	for (static int k = 2; k < n; k *= 2) {
		R.resize(n);
        rt.resize(n);

		auto x = polar(1.0L, acos(-1.0L) / k);
        for (int i = k; i < 2 * k; i++)
            rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
	}

    vector<int> rev(n);
    for (int i = 0; i < n; i++)
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;

    for (int i = 0; i < n; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);

	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k)
            for (int j = 0; j < k; j++) {
                auto x = (double *) &rt[j + k], y = (double *) &a[i + j + k];
                Complex z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);

                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}

template<typename T, typename U>
vector<T> convolution(const vector<U> &a, const vector<U> &b) {
    if (a.empty() || b.empty()) return {};

    vector<T> res((int) a.size() + (int) b.size() - 1);
    int L = 32 - __builtin_clz((int) res.size());
    int n = 1 << L;

    vector<Complex> in(n), out(n);
    copy(a.begin(), a.end(), in.begin());

    for (int i = 0; i < (int) b.size(); i++)
        in[i].imag(b[i]);

    FFT(in);
    for (Complex &x: in)
        x *= x;

    for (int i = 0; i < n; i++)
        out[i] = in[-i & (n - 1)] - conj(in[i]);

    FFT(out);
    for (int i = 0; i < (int) res.size(); i++)
        res[i] = round(imag(out[i]) / (4 * n));

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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