#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int T; cin >> T;
    while (T--) {
        int n; long double c;
        cin >> n >> c;

        long double modifier = n >= 10000000 ? 2.0L : (n > 9800000 ? 1.0L + (n - 9800000.0L) / 200000.0L : (n - 9500000.0L) / 300000.0L);

        long double ans = max(c + modifier, 0.0L);
        cout << ans << "\n";
    }
}