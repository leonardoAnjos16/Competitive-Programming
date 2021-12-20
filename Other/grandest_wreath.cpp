#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> tree;

pair<int, int> max_depth(int node, int parent = -1, int depth = 1) {
    pair<int, int> ans = make_pair(depth, node);
    for (auto child: tree[node])
        if (child != parent)
            ans = max(ans, max_depth(child, node, depth + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V1; cin >> V1;

    tree.assign(V1, vector<int>());
    for (int i = 1; i < V1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    int ans = max_depth(max_depth(0).second).first;

    int V2; cin >> V2;

    tree.assign(V2, vector<int>());
    for (int i = 1; i < V2; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    ans += max_depth(max_depth(0).second).first;
    cout << ans << "\n";
}