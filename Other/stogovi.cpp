#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 20;

vector<int> parent, depth;
vector<vector<int>> up;

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

    int N; cin >> N;

    vector<int> top(N + 1);
    vector<int> actual(N + 1, 0);

    parent.assign(N + 1, 0);
    depth.assign(N + 1, 0);
    up.assign(LOG, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        char op; int v;
        cin >> op >> v;

        if (op == 'a') {
            top[i] = i;
            actual[i] = i;
            parent[i] = actual[v];
            depth[i] = depth[actual[v]] + 1;

            up[0][i] = actual[v];
            for (int j = 1; j < LOG; j++)
                up[j][i] = up[j - 1][up[j - 1][i]];
        } else if (op == 'b') {
            assert(~top[actual[v]]);
            actual[i] = parent[actual[v]];
            cout << top[actual[v]] << "\n";
        } else {
            int w; cin >> w;
            actual[i] = actual[v];

            int u = lca(actual[i], actual[w]);
            cout << depth[u] << "\n";
        }
    }
}