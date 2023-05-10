#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const ldouble EPS = 1e-9;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

ldouble prod(ldouble x1, ldouble x2, int y1, int y2, ldouble x) {
    ldouble m = (y2 - y1) / (x2 - x1);
    return y1 + m * (x - x1);
}

ldouble work(int T, ldouble x1, ldouble x2, int y1, int y2) {
    ldouble l = x1, r = x2;
    for (int i = 0; i < 50; i++) {
        ldouble m1 = l + (r - l) / 3.0L;
        ldouble m2 = r - (r - l) / 3.0L;

        ldouble a1 = prod(x1, x2, y1, y2, m1) * (T - m1);
        ldouble a2 = prod(x1, x2, y1, y2, m2) * (T - m2);

        if (sign(a1 - a2) < 0) l = m1;
        else r = m2;
    }

    return prod(x1, x2, y1, y2, l) * (T - l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int X, T;
    cin >> X >> T;

    ldouble ans = 200.0L * T / 3.0L;
    ans = max(ans, work(T, 0.0L, T / 6.0L, 0, X));
    ans = max(ans, work(T, T / 6.0L, T / 3.0L, X, 100));

    cout << ans << "\n";
}