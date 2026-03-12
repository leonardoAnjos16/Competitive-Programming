#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> tree;
vector<int> nodes;
vector<bool> rem;
vector<char> ans;

void get_nodes(int node, int parent = -1) {
    nodes[node] = 1;
    for (int child: tree[node])
        if (child != parent && !rem[child]) {
            get_nodes(child, node);
            nodes[node] += nodes[child];
        }
}

int centroid(int size, int node, int parent = -1) {
    for (int child: tree[node])
        if (child != parent && !rem[child] && 2 * nodes[child] > size)
            return centroid(size, child, node);

    return node;
}

bool solve(int node = 0, char rank = 'A') {
    if (rank > 'Z') return false;

    get_nodes(node);
    int c = centroid(nodes[node], node);

    rem[c] = true;
    ans[c] = rank;

    for (int child: tree[c])
        if (!rem[child] && !solve(child, rank + 1))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    nodes.resize(n);
    rem.assign(n, false);
    ans.resize(n);

    assert(solve());
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}