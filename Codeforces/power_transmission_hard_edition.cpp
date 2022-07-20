#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> poles(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        poles[i] = make_pair(x, y);
    }

    map<pair<int, int>, set<pair<int, int>>> lines;
    for (int i = 0; i < n; i++) {
        map<pair<int, int>, pair<int, int>> dirs;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            auto [xi, yi] = poles[i];
            auto [xj, yj] = poles[j];

            int dx = xj - xi;
            int dy = yj - yi;

            if (!dx && dy < 0) dy = -dy;
            else if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }

            int g = gcd(abs(dx), abs(dy));
            dx /= g; dy /= g;

            pair<int, int> d = make_pair(dx, dy);
            pair<int, int> mn = min(poles[i], poles[j]);

            if (!dirs.count(d)) dirs[d] = mn;
            else dirs[d] = min(dirs[d], mn);
        }

        for (auto [dir, point]: dirs)
            lines[dir].insert(point);
    }

    int cnt = 0;
    long ans = 0LL;

    for (auto [dir, points]: lines) {
        int size = points.size();
        ans -= size * (size - 1LL) / 2LL;
        cnt += size;
    }

    ans += cnt * (cnt - 1LL) / 2LL;
    cout << ans << "\n";
}