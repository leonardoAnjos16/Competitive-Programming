#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Complex complex<ldouble>

const ldouble PI = acosl(-1.0L);

template<typename T>
struct FFT {
public:
  vector<T> multiply(vector<T> &a, vector<T> &b) {
    int _n = (int) a.size() + (int) b.size();

    int n = 1;
    while (n < _n) n <<= 1;

    vector<Complex> ca(n), cb(n);
    for (int i = 0; i < (int) a.size(); i++)
      ca[i] = Complex(a[i]);

    for (int i = 0; i < (int) b.size(); i++)
      cb[i] = Complex(b[i]);

    vector<Complex> ya = fft(ca);
    vector<Complex> yb = fft(cb);

    vector<Complex> y(n);
    for (int i = 0; i < n; i++)
      y[i] = ya[i] * yb[i];

    vector<Complex> cc = fft(y, true);

    vector<T> c(n);
    for (int i = 0; i < n; i++)
      c[i] = cc[i].real();

    return c;
  }

private:
  vector<Complex> fft(vector<Complex> &p, bool inverse = false) {
    int n = p.size();
    if (n == 1) return p;

    vector<Complex> pe(n >> 1), po(n >> 1);
    for (int i = 0; i < n; i++) {
      if (i & 1) po[i >> 1] = p[i];
      else pe[i >> 1] = p[i];
    }

    vector<Complex> ye = fft(pe, inverse);
    vector<Complex> yo = fft(po, inverse);

    ldouble theta = 2.0L * PI / n;
    if (inverse) theta = -theta;

    Complex w(1.0L);
    vector<Complex> y(n);

    for (int i = 0; i < (n >> 1); i++) {
      y[i] = ye[i] + w * yo[i];
      y[(n >> 1) + i] = ye[i] - w * yo[i];

      if (inverse) {
        y[i] /= 2.0L;
        y[(n >> 1) + i] /= 2.0L;
      }

      w *= Complex(cosl(theta), sinl(theta));
    }

    return y;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<llong> a = { 1LL, 2LL };
  vector<llong> b = { 3LL, 4LL };

  vector<llong> c = FFT<llong>().multiply(a, b);
  for (int i = 0; i < 4; i++)
    cout << c[i] << "\n";
}