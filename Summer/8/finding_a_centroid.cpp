#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<vector<int>> tree;
vector<int> nodes;

void get_nodes(int node = 0, int parent = -1) {
    nodes[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            get_nodes(child, node);
            nodes[node] += nodes[child];
        }
}

int centroid(int node = 0, int parent = -1) {
    for (int child: tree[node])
        if (child != parent && 2 * nodes[child] > n)
            return centroid(child, node);

    return node + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    nodes.resize(n);
    get_nodes();

    int ans = centroid();
    cout << ans << "\n";
}