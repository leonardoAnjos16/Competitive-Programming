#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 20;

int N;
vector<int> A;
vector<vector<int>> tree;

vector<long> sum;
vector<int> parent, height;
vector<vector<int>> up;

void get_sum_parent_and_height(int n = 0, int p = 0, int h = 0) {
    sum[n] = A[n];
    parent[n] = p;
    height[n] = h;

    for (auto c: tree[n])
        if (c != p) {
            get_sum_parent_and_height(c, n, h + 1);
            sum[n] += sum[c];
        }
}

void get_up() {
    up.assign(LOG, vector<int>(N));
    for (int i = 0; i < N; i++)
        up[0][i] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < N; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];
}

int lca(int u, int v) {
    if (height[u] > height[v]) swap(u, v);

    int diff = height[v] - height[u];
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

    int T; cin >> T;
    while (T--) {
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        tree.assign(N, vector<int>());
        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        sum.resize(N);
        parent.resize(N);
        height.resize(N);
        get_sum_parent_and_height();
        get_up();

        int Q; cin >> Q;
        while (Q--) {
            int U, V, X;
            cin >> U >> V >> X;
            U--; V--; X--;

            int UV = lca(U, V), UX = lca(U, X), VX = lca(V, X);
            if (UV == U || UV == V || UX == U || VX == V || lca(X, UV) == X) cout << sum[X];
            else if (UX == X) cout << (sum[X] - sum[U] + sum[V]);
            else if (VX == X) cout << (sum[X] - sum[V] + sum[U]);
            else cout << sum[X];

            if (Q) cout << " ";
        }

        cout << "\n";
    }
}