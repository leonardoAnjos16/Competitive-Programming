#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 25;

int h, w;
vector<vector<int>> tree;
vector<int> parent, depth;
vector<vector<int>> up;

int to_id(int i, int j) {
    return w * i + j;
}

void get_parent_and_depth(int node = 0, int p = -1) {
    for (auto child: tree[node])
        if (child != p) {
            parent[child] = node;
            depth[child] = depth[node] + 1;
            get_parent_and_depth(child, node);
        }
}

void get_up() {
    parent.assign(h * w, 0);
    depth.assign(h * w, 0);
    get_parent_and_depth();

    up.assign(LOG, vector<int>(h * w));
    for (int i = 0; i < h * w; i++)
        up[0][i] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < h * w; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];
}

int lca(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);

    int diff = depth[v] - depth[u];
    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i))
            v = up[i][v];

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--)
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }

    return parent[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;

    cin.ignore();
    vector<string> grid(h + 1);

    for (int i = 0; i <= h; i++)
        getline(cin, grid[i]);

    tree.assign(w * h, vector<int>());
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= 2 * w; j += 2) {
            int u = to_id(i - 1, j / 2);
            if (grid[i - 1][j] != '_') {
                int v = to_id(i - 2, j / 2);
                tree[u].push_back(v);
                tree[v].push_back(u);
            }

            if (grid[i][j - 1] != '|') {
                int v = to_id(i - 1, (j - 2) / 2);
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
        }
    }

    get_up();

    int m; cin >> m;
    vector<int> nodes(m);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        nodes[i] = to_id(x - 1, y - 1);
    }

    long ans = 0LL;
    for (int i = 1; i < m; i++) {
        int u = nodes[i - 1];
        int v = nodes[i];
        int w = lca(u, v);

        ans += depth[u] + depth[v] - 2 * depth[w];
    }

    cout << ans << "\n";
}