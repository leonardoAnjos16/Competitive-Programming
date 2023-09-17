#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int ROOT = 62;
const int MAX = 1e5 + 5;
const int MOD = 998244353;

int facts[MAX], invs[MAX];

int exp(int a, int n) {
	if (!n) return 1;

	int ans = exp(a, n >> 1);
	ans = (1LL * ans * ans) % MOD;

	if (!(n & 1)) return ans;
	return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int a, int m) {
	return exp(a, m - 2);
}

void NTT(vector<llong> &a) {
	static vector<llong> rt(2, 1);
	int n = a.size(), L = 31 - __builtin_clz(n);

	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		llong z[] = { 1LL, exp(ROOT, MOD >> s) };

		for (int i = k; i < 2 * k; i++)
			rt[i] = (rt[i / 2] * z[i & 1]) % MOD;
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
				llong &ai = a[i + j];
				llong z = rt[j + k] * a[i + j + k] % MOD;

				a[i + j + k] = ai - z + (z > ai ? MOD : 0);
				ai += (ai + z >= MOD ? z - MOD : z);
			}
}

vector<llong> convolution(const vector<llong> &a, const vector<llong> &b) {
	if (a.empty() || b.empty()) return {};

	int s = (int) a.size() + (int) b.size() - 1;
	int B = 32 - __builtin_clz(s);
	int n = 1 << B;

	int inv = mod_mult_inv(n, MOD);
	vector<llong> L(a), R(b), out(n);

	L.resize(n);
	R.resize(n);

	NTT(L);
	NTT(R);

	for (int i = 0; i < n; i++)
		out[-i & (n - 1)] = (((L[i] * R[i]) % MOD) * inv) % MOD;

	NTT(out);
	return { out.begin(), out.begin() + s };
}

vector<int> add_k(vector<int> &coeffs, int n, int k) {
    vector<llong> a(n + 1);
    for (int i = 0; i <= n; i++)
        a[i] = (1LL * coeffs[i] * facts[i]) % MOD;

    vector<llong> b(n + 1);
    for (int i = 0; i <= n; i++)
        b[i] = (1LL * exp(k, i) * invs[i]) % MOD;

    vector<llong> rb(n + 1);
    for (int i = 0; i <= n; i++)
        rb[i] = b[n - i];

    vector<llong> c = convolution(a, rb);
    for (int i = 0; i < (int) c.size(); i++)
        c[i] = ((c[i] % MOD) + MOD) % MOD;

    vector<int> ncoeffs(n + 1);
    for (int i = 0; i <= n; i++)
        ncoeffs[i] = (1LL * c[n + i] * invs[i]) % MOD;

    return ncoeffs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    facts[0] = invs[0] = 1;
    for (int i = 1; i < MAX; i++) {
        facts[i] = (1LL * facts[i - 1] * i) % MOD;
        invs[i] = mod_mult_inv(facts[i], MOD);
    }

    int N, K;
    cin >> N >> K;

    K = (K + MOD) % MOD;

    vector<int> t(N + 1);
    for (int i = 0; i <= N; i++)
        cin >> t[i];

    vector<int> p(N + 1);
    for (int i = 0; i <= N; i++)
        cin >> p[i];

    vector<int> tk = add_k(t, N, K);
    vector<int> pk = add_k(p, N, (MOD - K) % MOD);

    for (int i = 0; i <= N; i++) {
        if (i) cout << " ";

        int ans = (tk[i] + pk[i]) % MOD;
        cout << ans;
    }

    cout << "\n";
}