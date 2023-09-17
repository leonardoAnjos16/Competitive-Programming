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
        res[i] = round(imag(out[i]) / (4 * n)); // remove round if the output is double

    return res;
}

template<int M>
vector<llong> modConvolution(const vector<llong> &a, const vector<llong> &b) {
	if (a.empty() || b.empty()) return {};

	vector<llong> res((int) a.size() + (int) b.size() - 1);
	int B = 32 - __builtin_clz((int) res.size());
	int cut = (int) sqrt(M);
	int n = 1 << B;

	vector<Complex> L(n), R(n), outs(n), outl(n);
	for (int i = 0; i < (int) a.size(); i++)
		L[i] = Complex((int) a[i] / cut, (int) a[i] % cut);

	for (int i = 0; i < (int) b.size(); i++)
		R[i] = Complex((int) b[i] / cut, (int) b[i] % cut);

	FFT(L);
	FFT(R);

	for (int i = 0; i < n; i++) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}

	FFT(outl);
	FFT(outs);

	for (int i = 0; i < (int) res.size(); i++) {
		llong av = (llong) (real(outl[i]) + 0.5), cv = (llong) (imag(outs[i]) + 0.5);
		llong bv = (llong) (imag(outl[i]) + 0.5) + (llong) (real(outs[i]) + 0.5);
		res[i] = ((((av % M) * cut + bv) % M) * cut + cv) % M;
	}

	return res;
}