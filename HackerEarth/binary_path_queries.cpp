#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 25;
const int MAX = 5e5 + 5;
const int MOD = 1e9 + 7;

vector<int> A, vals, rvals, dists, parents, pots;
vector<vector<int>> tree, up;
bitset<MAX> vis;

void get_vals_and_dists(int v = 0) {
    vis[v] = true;
    for (auto u: tree[v]) {
        if (!vis[u]) {
            vals[u] = (vals[v] << 1) + A[u];
            vals[u] %= MOD;

            parents[u] = v;
            dists[u] = dists[v] + 1;

            rvals[u] = rvals[v];
            if (A[u]) {
                rvals[u] += pots[dists[u]];
                rvals[u] %= MOD;
            }

            get_vals_and_dists(u);
        }
    }
}

int lca(int u, int v) {
    if (dists[u] < dists[v]) swap(u, v);

    int diff = dists[u] - dists[v];
    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i))
            u = up[u][i];

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--)
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }

    return parents[u];
}

void extended_euclidean(long a, long b, long &x, long &y) {
    if (!b) {
        x = 1LL;
        y = 0LL;
    } else {
        extended_euclidean(b, a % b, x, y);
        long aux = x; x = y;
        y = aux - a / b * y;
    }
}

long mod_mult_inv(long a, long m) {
    long x, y;
    extended_euclidean(a, m, x, y);
    return (x % m + m) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pots.assign(MAX, 1);
    for (int i = 1; i < MAX; i++) {
        pots[i] = pots[i - 1] << 1;
        pots[i] %= MOD;
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

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

        vals.resize(N);
        vals[0] = A[0];

        rvals.resize(N);
        rvals[0] = A[0];

        dists.resize(N);
        dists[0] = 0;

        parents.resize(N);
        parents[0] = 0;

        vis.reset();
        get_vals_and_dists();

        up.assign(N, vector<int>(LOG));
        for (int i = 0; i < N; i++)
            up[i][0] = parents[i];

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < N; j++)
                up[j][i] = up[up[j][i - 1]][i - 1];

        int Q; cin >> Q;
        while (Q--) {
            int u, v;
            cin >> u >> v;
            u--; v--;

            long urval = rvals[u];
            long vval = vals[v];

            int w = lca(u, v);
            long wval = vals[w];
            long wrval = rvals[parents[w]];

            if (w) {
                urval = (urval - wrval + MOD) % MOD;
                long aux = mod_mult_inv(pots[dists[w]], MOD);
                urval = (urval * aux) % MOD;
            }

            long aux = (wval * pots[dists[v] - dists[w]]) % MOD;
            vval = (vval - aux + MOD) % MOD;

            long ans = (urval * pots[dists[v] - dists[w]]) % MOD;
            ans = (ans + vval) % MOD;

            cout << ans;
            if (Q) cout << " ";
        }

        cout << "\n";
    }
}