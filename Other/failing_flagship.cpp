#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

const ldouble EPS = 1e-9;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

ldouble angle(string &s) {
    if (s == "N") return 0.0L;
    if (s == "E") return 90.0L;
    if (s == "S") return 180.0L;
    if (s == "W") return 270.0L;

    int n = s.size();

    string dir = "NE";
    if (s[n - 2] == 'S' && s[n - 1] == 'E') dir = "ES";
    else if (s[n - 2] == 'S') dir = "SW";
    else if (s[n - 1] == 'W') dir = "WN";

    ldouble ans = 45.0L;
    if (dir == "ES") ans = 135.0L;
    else if (dir == "SW") ans = 225.0L;
    else if (dir == "WN") ans = 315.0L;

    ldouble size = 45.0L;
    for (int i = n - 3; i >= 0; i--) {
        size /= 2.0;
        if (s[i] == dir[0]) ans -= size;
        else ans += size;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    string X, Y;
    cin >> X >> Y;

    ldouble a1 = angle(X);
    ldouble a2 = angle(Y);

    if (sign(a1 - a2) > 0)
        swap(a1, a2);

    ldouble ans = min(a2 - a1, 360.0L - a2 + a1);
    cout << ans << "\n";
}