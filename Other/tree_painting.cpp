#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> p, sz, c;

void init(int node = 0, int parent = -1) {
    sz[node] = 1;
    p[node] = parent;

    for (int child: tree[node])
        if (child != parent) {
            init(child, node);
            sz[node] += sz[child];
        }
}

void color(int node, int parent) {
    c[node] = 1;
    for (int child: tree[node])
        if (child != parent)
            color(child, node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    p.resize(n);
    sz.resize(n);
    init();

    bool possible = false;
    for (int i = 0; i < n && !possible; i++)
        if (sz[i] == n / 2) {
            possible = true;
            c.assign(n, 0);
            color(i, p[i]);
        }

    cout << (possible ? "YES" : "NO") << "\n";
    if (possible) {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << c[i];
        }

        cout << "\n";
    }

}