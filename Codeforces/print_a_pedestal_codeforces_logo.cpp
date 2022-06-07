#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            int second = min(mid - 1, n - mid - 1);
            int third = n - mid - second;

            if (mid <= second || second <= third) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        int second = min(ans - 1, n - ans - 1);
        int third = n - ans - second;

        cout << second << " " << ans << " " << third << "\n";
    }
}