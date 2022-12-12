#include <bits/stdc++.h>

using namespace std;

int k;
vector<vector<int>> tree;

pair<int, int> shuttles(int node = 0, int parent = -1) {
    bool covered = false;
    int buses = 0, nodes = 1;

    for (int child: tree[node])
        if (child != parent) {
            auto [new_buses, new_nodes] = shuttles(child, node);
            if (node && !covered && new_buses * k > new_nodes)
                covered = true;

            buses += new_buses;
            nodes += new_nodes;
        }

    if (node && !covered) buses++;
    return make_pair(buses, nodes);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n >> k;

        tree.assign(n, vector<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        int ans = shuttles().first;
        cout << ans << "\n";
    }
}