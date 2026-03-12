#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 2e4 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        set<int> vertical;
        set<tuple<int, int, int, int>> lines;

        while (n--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            if (x1 == x2) vertical.insert(x1);
            else {
                if (x1 > x2) {
                    swap(x1, x2);
                    swap(y1, y2);
                }

                int dx = x2 - x1, dy = y2 - y1;
                int g = gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;

                int l = -MAX, r = MAX, k;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (x1 + mid * dx < 0) l = mid + 1;
                    else r = mid - 1, k = mid;
                }

                int x = x1 + k * dx, y = y1 + k * dy;
                assert(x >= 0 && x - dx < 0);
                lines.emplace(dy, dx, x, y);
            }
        }

        map<pair<int, int>, int> cnt;
        for (auto [dy, dx, x, y]: lines)
            cnt[make_pair(dy, dx)]++;

        llong ans = 0LL;
        for (int x: vertical)
            ans += cnt[make_pair(0, 1)];

        for (auto [dy, dx, x, y]: lines) {
            if (!dy) ans += (int) vertical.size();
            else if (dy > 0) ans += cnt[make_pair(-dx, dy)];
            else ans += cnt[make_pair(dx, -dy)];
        }

        ans /= 2LL;
        cout << ans << "\n";
    }
}