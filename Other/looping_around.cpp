#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<bool> vis;

void visit(vector<int> &horizontal, vector<int> &vertical, int i = 0) {
    vis[i] = true;
    if (!vis[horizontal[i]]) visit(horizontal, vertical, horizontal[i]);
    if (!vis[vertical[i]]) visit(horizontal, vertical, vertical[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = make_pair(x, y);
        }

        sort(points.begin(), points.end());

        map<int, set<pair<int, int>>> xs, ys;
        for (int i = 0; i < n; i++) {
            auto [x, y] = points[i];
            xs[y].emplace(x, i);
            ys[x].emplace(y, i);
        }

        bool possible = true;
        multiset<int> hlines;
        vector<int> horizontal(n, -1), vertical(n, -1);

        for (int i = 0; i < n && possible; i++) {
            auto [x, y] = points[i];
            if (~horizontal[i]) hlines.erase(hlines.find(y));
            else {
                auto it = xs[y].upper_bound(make_pair(x, n));
                if (it == xs[y].end()) possible = false;
                else {
                    horizontal[i] = it->second;
                    horizontal[it->second] = i;
                    hlines.insert(y);
                }
            }

            if (vertical[i] == -1) {
                auto it = ys[x].upper_bound(make_pair(y, n));
                if (it == ys[x].end()) possible = false;
                else {
                    auto line = hlines.upper_bound(y);
                    if (line != hlines.end() && *line < it->first) possible = false;
                    else {
                        vertical[i] = it->second;
                        vertical[it->second] = i;
                    }
                }
            }
        }

        if (!possible) cout << "NO\n";
        else {
            vis.assign(n, false);
            visit(horizontal, vertical);

            for (int i = 0; i < n && possible; i++)
                if (!vis[i]) possible = false;

            cout << (possible ? "YES" : "NO") << "\n";
        }
    }
}