#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 21;

int N;
vector<vector<int>> tree;
vector<int> parent, height;
vector<vector<int>> up;
vector<int> sum;

int roads(int v = 0, int p = -1) {
    int ans = 0;
    for (auto u: tree[v])
        if (u != p) {
            ans += roads(u, v);
            sum[v] += sum[u];
        }

    if (v && !sum[v]) ans++;
    return ans;
}

void get_parent_and_height(int v = 0, int p = -1) {
    if (~p) {
        parent[v] = p;
        height[v] = height[p] + 1;
    }

    for (auto u: tree[v])
        if (u != p)
            get_parent_and_height(u, v);
}

void get_up() {
    parent.assign(N, 0);
    height.assign(N, 0);
    get_parent_and_height();

    up.assign(N, vector<int>(LOG));
    for (int i = 0; i < N; i++)
        up[i][0] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < N; j++)
            up[j][i] = up[up[j][i - 1]][i - 1];
}

int lca(int u, int v) {
    if (height[u] < height[v]) swap(u, v);

    int diff = height[u] - height[v];
    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i))
            u = up[u][i];

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--)
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }

    return parent[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;

        tree.assign(N, vector<int>());
        for (int i = 1; i < N; i++) {
            int A, B;
            cin >> A >> B;

            tree[A - 1].push_back(B - 1);
            tree[B - 1].push_back(A - 1);
        }

        get_up();

        vector<vector<int>> nodes(N, vector<int>());

        vector<int> cnt(N, 0);
        vector<int> lcas(N, -1);

        for (int i = 0; i < N; i++) {
            int F; cin >> F;
            cnt[--F]++;

            if (lcas[F] == -1) lcas[F] = i;
            else lcas[F] = lca(lcas[F], i);
        }

        sum.assign(N, 1);
        for (int i = 0; i < N; i++)
            if (~lcas[i])
                sum[lcas[i]] -= cnt[i];

        int ans = roads();
        cout << "Case #" << t << ": " << ans << "\n";
    }
}