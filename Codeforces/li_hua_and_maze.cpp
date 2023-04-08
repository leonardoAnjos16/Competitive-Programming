#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = (x1 > 1) + (x1 < n) + (y1 > 1) + (y1 < m);
        ans = min(ans, (x2 > 1) + (x2 < n) + (y2 > 1) + (y2 < m));
        cout << ans << "\n";
    }
}