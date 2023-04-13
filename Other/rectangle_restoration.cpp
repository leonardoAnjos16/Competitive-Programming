#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(6) << fixed;

    int x, y;
    cin >> x >> y;

    bool possible = false;
    ldouble ans = 1e18 + 5;

    if (y - x > 0) {
        possible = true;
        ans = min(ans, x + 2.0L * (y - x));
    }

    if (2 * y - x > 0) {
        possible = true;
        ans = min(ans, x + y - x / 2.0L);
    }

    if (y - x > 0 && 2 * x - y > 0) {
        possible = true;
        ans = min(ans, 2.0L * (y - x) + 2.0L * (2 * x - y));
    }

    if (!possible) cout << "-1\n";
    else cout << ans << "\n";
}