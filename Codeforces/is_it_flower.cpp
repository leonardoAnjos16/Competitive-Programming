#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> g;
vector<bool> vis;

bool get_cycle(vector<int> &cycle, int start, int v, bool mid = false, int prev = -1) {
    if (prev != -1 && v == start) return true;
    if (vis[v]) return false;

    vis[v] = true;
    cycle.push_back(v);

    for (int u: g[v])
        if (u != prev && (!mid || (int) g[u].size() > 2) && get_cycle(cycle, start, u, mid, v))
            return true;

    cycle.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        g.assign(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }

        vector<int> mid;
        vis.assign(n, false);

        bool found = false;
        for (int i = 0; i < n && !found; i++)
            if ((int) g[i].size() > 2) {
                found = true;
                get_cycle(mid, i, i, true);
            }

        if (!found || mid.empty()) cout << "NO\n";
        else {
            int k = mid.size();
            assert(k >= 3);

            vis.assign(n, false);
            for (int v: mid)
                vis[v] = true;

            bool flower = true;
            for (int v: mid) {
                if ((int) g[v].size() != 4) flower = false;
                else {
                    vis[v] = false;
                    vector<int> curr;

                    if (!get_cycle(curr, v, v) || (int) curr.size() != k)
                        flower = false;
                }
            }

            flower &= n == 1LL * k * k;
            flower &= m == k * (k + 1LL);

            cout << (flower ? "YES" : "NO") << "\n";
        }
    }
}