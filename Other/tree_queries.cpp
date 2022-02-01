#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> tree;
vector<set<int>> queries, ids;
vector<bool> ans;

void solve(int node = 0, int parent = -1) {
    for (auto child: tree[node])
        if (child != parent)
            for (auto id: ids[child]) {
                queries[id].erase(child);
                if (queries[id].empty())
                    ans[id] = true;
            }

    for (auto child: tree[node])
        if (child != parent)
            solve(child, node);

    for (auto child: tree[node])
        if (child != parent)
            for (auto id: ids[child])
                queries[id].insert(child);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    queries.assign(m, set<int>());
    ids.assign(n, set<int>());
    ans.assign(m, false);

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        while (k--) {
            int v; cin >> v;
            if (v == 1) continue;

            queries[i].insert(v - 1);
            ids[v - 1].insert(i);
        }

        if (queries[i].empty())
            ans[i] = true;
    }

    solve();

    for (int i = 0; i < m; i++)
        cout << (ans[i] ? "YES" : "NO") << "\n";
}