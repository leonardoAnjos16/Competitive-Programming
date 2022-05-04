#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> tree;
vector<int> leaves;

void get_leaves(int node = 0) {
    if (tree[node].empty()) leaves[node] = 1;
    else {
        leaves[node] = 0;
        for (int child: tree[node]) {
            get_leaves(child);
            leaves[node] += leaves[child];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V; cin >> V;

    tree.assign(V, vector<int>());
    for (int i = 1; i < V; i++) {
        int u, v;
        cin >> u >> v;
        tree[u - 1].push_back(v - 1);
    }

    leaves.resize(V);
    get_leaves();

    long ans = 0LL;
    for (int i = 0; i < V; i++)
        if ((int) tree[i].size() == 2)
            ans += 1LL * leaves[tree[i][0]] * leaves[tree[i][1]];

    cout << ans << "\n";
}