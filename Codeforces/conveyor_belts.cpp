#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int square(int n, int x, int y) {
    int ans = n - min(x, y);
    if (ans <= 0) ans--;

    if (ans > 0) {
        if (2 * ans > abs(x - y)) return ans;
        return ans + abs(x - y) - 2 * ans + 1;
    }

    return abs(ans) + abs(x - y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        int ans = abs(square(n / 2, x1 - 1, y1 - 1) - square(n / 2, x2 - 1, y2 - 1));
        cout << ans << "\n";
    }
}