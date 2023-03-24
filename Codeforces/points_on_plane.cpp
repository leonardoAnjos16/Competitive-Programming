#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        llong n; cin >> n;

        llong l = 1LL, r = 1e9, k1 = -1LL;
        while (l <= r) {
            llong mid = (l + r) / 2LL;
            if (4LL * mid * mid < n) l = mid + 1LL;
            else r = mid - 1LL, k1 = mid;
        }

        l = 1LL; r = 1e9; llong k2 = -1LL;
        while (l <= r) {
            llong mid = (l + r) / 2LL;
            if (4LL * mid * (mid - 1LL) + 1 < n) l = mid + 1LL;
            else r = mid - 1LL, k2 = mid;
        }

        llong ans = min(2LL * k1 - 1LL, 2LL * (k2 - 1LL));
        cout << ans << "\n";
    }
}