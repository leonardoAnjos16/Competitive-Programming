const int ROOT = 62;
const int MOD = 998244353;

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