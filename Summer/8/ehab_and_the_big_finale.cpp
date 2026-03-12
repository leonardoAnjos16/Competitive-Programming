#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> tree;
vector<int> depth, heavy, last;

int get_heavy(int node = 0, int parent = -1) {
    int size = 1, mx_size = 0;
    for (int child: tree[node])
        if (child != parent) {
            depth[child] = depth[node] + 1;
            int aux = get_heavy(child, node);

            size += aux;
            if (aux > mx_size) {
                mx_size = aux;
                heavy[node] = child;
            }
        }

    return size;
}

void get_last(int node = 0, int parent = -1, int head = 0) {
    last[head] = node;
    for (int child: tree[node])
        if (child != parent) {
            if (child == heavy[node]) get_last(child, node, head);
            else get_last(child, node, child);
        }
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

    depth.assign(n, 0);
    heavy.assign(n, -1);
    get_heavy();

    last.resize(n);
    get_last();

    cout << "d 1\n";
    cout.flush();

    int d; cin >> d;

    int v = 0;
    while (depth[v] < d) {
        cout << "d " << (last[v] + 1) << "\n";
        cout.flush();

        int dist; cin >> dist;
        // dist = d + depth[last[v]] - 2 * x
        // 2 * x = d + depth[last[v]] - dist
        // x = (d + depth[last[v]] - dist) / 2

        int lca_depth = (d + depth[last[v]] - dist) / 2;
        while (depth[v] < lca_depth) v = heavy[v];

        if (depth[v] < d) {
            cout << "s " << (v + 1) << "\n";
            cout.flush();

            cin >> v;
            v--;
        }
    }

    cout << "! " << (v + 1) << "\n";
    cout.flush();
}