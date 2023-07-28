#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m, k, H;
        cin >> n >> m >> k >> H;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int h; cin >> h;

            int diff = abs(H - h);
            if (!diff || diff % k) continue;

            int steps = diff / k + 1;
            if (steps <= m) ans++;
        }

        cout << ans << "\n";
    }
}