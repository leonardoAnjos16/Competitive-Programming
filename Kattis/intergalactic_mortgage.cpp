#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

const ldouble EPS = 1e-9;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

ldouble remaining(int X, int Y, ldouble R, int months) {
    ldouble rate = 1.0L + R / 12.0L;
    ldouble prate = pow(rate, months);

    ldouble ans = X * prate;
    ans -= 12.0L * Y * (prate - 1.0L) / R;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, N; ldouble r;
    while (cin >> X >> Y >> N >> r, X || Y || N || sign(r)) {
        ldouble R = r / 100.0L;

        bool possible = false;
        int lo = 0, hi = 12 * N;

        while (lo <= hi && !possible) {
            int mid = (lo + hi) / 2;
            if (sign(remaining(X, Y, R, mid)) > 0) lo = mid + 1;
            else hi = mid - 1, possible = true;
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}