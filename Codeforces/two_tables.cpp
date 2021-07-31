#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        long W, H;
        cin >> W >> H;

        long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long w, h;
        cin >> w >> h;

        if (w + x2 - x1 > W && h + y2 - y1 > H) {
            cout << "-1\n";
            continue;
        }

        long ans = LLONG_MAX;
        if (w + x2 - x1 <= W)
            ans = min(ans, min(max(w - x1, 0LL), max(x2 - (W - w), 0LL)));

        if (h + y2 - y1 <= H)
            ans = min(ans, min(max(h - y1, 0LL), max(y2 - (H - h), 0LL)));

        cout << ans << "\n";
    }
}