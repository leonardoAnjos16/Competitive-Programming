#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int x, y;
        cin >> x >> y;

        cout << "Case #" << t << ":\n";
        if (!x && !y) cout << "0\n";
        else {
            bool neg_x = x < 0;
            bool neg_y = y < 0;

            int cx = 0, cy = 0;
            x = abs(x); y = abs(y);

            int cnt = 0;
            vector<pair<int, int>> ans;

            while (cnt + 1 < x - cx) {
                cx += ++cnt;
                ans.emplace_back(cx, 0);
            }

            int steps = ++cnt - x + cx;
            if (steps >= y) {
                if ((steps - y) & 1) {
                    cnt++;
                    ans.emplace_back(x, y + 1);

                    if (!(cnt & 1)) {
                        cnt++;
                        ans.emplace_back(x, y + 1);
                    }
                }

                ans.emplace_back(x, y);
            } else {
                cy += steps;
                ans.emplace_back(x, cy);

                while (cnt + 1 < y - cy) {
                    cy += ++cnt;
                    ans.emplace_back(x, cy);
                }

                cnt++;
                if ((cnt - y + cy) & 1) {
                    cnt++;
                    ans.emplace_back(x, y + 1);

                    if (!(cnt & 1)) {
                        cnt++;
                        ans.emplace_back(x, y + 1);
                    }
                }

                ans.emplace_back(x, y);
            }

            cout << cnt << "\n";
            for (auto pos: ans) {
                cx = neg_x ? -pos.first : pos.first;
                cy = neg_y ? -pos.second : pos.second;
                cout << cx << " " << cy << "\n";
            }
        }
    }
}