#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> g;
vector<int> vis;

bool find_cycle(int v, vector<int> &path, int prev = -1) {
    if (vis[v] == 2) return false;
    if (vis[v] == 1) {
        path.push_back(v + 1);
        return true;
    }

    vis[v] = 1;
    path.push_back(v + 1);

    for (int u: g[v])
        if (u != prev && find_cycle(u, path, v))
            return true;

    path.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<int> path;
    vis.assign(n, 0);

    for (int i = 0; i < n; i++)
        if (!vis[i] && find_cycle(i, path)) {
            int idx = 0, k = path.size();
            while (idx < k && path[idx] != path.back()) idx++;

            cout << (k - idx) << "\n";
            for (int j = idx; j < k; j++) {
                if (j > idx) cout << " ";
                cout << path[j];
            }

            cout << "\n";
            return 0;
        }

    cout << "IMPOSSIBLE\n";
}