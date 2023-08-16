#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

const ldouble EPS = 1e-9;
const ldouble INF = 1e18 + 5;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

struct Parabola {
    int a, b, c;

    Parabola() {}
    Parabola(int a, int b, int c): a(a), b(b), c(c) {}

    ldouble get_y(ldouble x) {
        return a * x * x + b * x + c;
    }
};

pair<ldouble, ldouble> get_ys(vector<Parabola> &parabolas, ldouble x) {
    ldouble mny = INF, mxy = -INF;
    for (Parabola &parabola: parabolas) {
        ldouble y = parabola.get_y(x);
        if (parabola.a < 0) mny = min(mny, y);
        else mxy = max(mxy, y);
    }

    return make_pair(mny, mxy);
}

ldouble diff(vector<Parabola> &parabolas, ldouble x) {
    auto [mny, mxy] = get_ys(parabolas, x);
    return mny - mxy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<Parabola> parabolas(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        parabolas[i] = Parabola(a, b, c);
    }

    ldouble l = -INF, r = INF;
    for (int i = 0; i < 500; i++) {
        ldouble m1 = l + (r - l) / 3.0L;
        ldouble m2 = r - (r - l) / 3.0L;

        ldouble d1 = diff(parabolas, m1);
        ldouble d2 = diff(parabolas, m2);

        if (sign(d1 - d2) < 0) l = m1;
        else r = m2;
    }

    ldouble x = (l + r) / 2.0L;
    auto [mny, mxy] = get_ys(parabolas, x);
    ldouble y = (mxy + mny) / 2.0L;

    cout << x << " " << y << "\n";
}