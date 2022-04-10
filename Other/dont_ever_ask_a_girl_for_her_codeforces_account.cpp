#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> tree;
vector<int> parent, nodes;

void get_parent_and_nodes(int node, int p = -1) {
    parent[node] = p;
    nodes[node] = 1;

    for (auto child: tree[node])
        if (child != p) {
            get_parent_and_nodes(child, node);
            nodes[node] += nodes[child];
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;

        tree.assign(N, vector<int>());
        for (int i = 1; i < N; i++) {
            int a, b;
            cin >> a >> b;

            tree[a - 1].push_back(b - 1);
            tree[b - 1].push_back(a - 1);
        }

        nodes.resize(N);
        parent.resize(N);
        get_parent_and_nodes(A - 1);

        long ans = 0LL;
        int node = B - 1;

        while (parent[node] != -1) {
            ans += 1LL * nodes[node] * (nodes[parent[node]] - nodes[node]);
            node = parent[node];
        }

        cout << ans << "\n";
    }
}