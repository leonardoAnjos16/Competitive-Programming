#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 62;
const int MOD = 1e9 + 7;

vector<vector<pair<int, llong>>> g;
vector<vector<int>> tree;
vector<int> nodes, vis;
vector<llong> x;
int cnt[2][MAX];

int sz;
llong seen;
llong basis[MAX];

void init(int v, int parent = -1) {
    nodes[v] = vis[v] = 1;
    for (auto [u, t]: g[v]) {
        if (u == parent) continue;

        if (!vis[u]) {
            x[u] = x[v] ^ t;
            tree[v].push_back(u);
            init(u, v);
            nodes[v] += nodes[u];
        } else if (vis[u] == 1) {
            bool done = false;
            llong sum = x[v] ^ x[u] ^ t;

            for (int i = 0; i < MAX && !done; i++) {
                if (!(sum & (1LL << i))) continue;

                if (basis[i]) sum ^= basis[i];
                else {
                    sz++;
                    seen |= sum;
                    basis[i] = sum;
                    done = true;
                }
            }
        }
    }

    vis[v] = 2;
}

int count_single(int node) {
    int ans = 0;
    for (int i = 0; i < MAX; i++) {
        if (seen & (1LL << i)) {
            int triples = (1LL << (sz - 1)) % MOD;
            triples = (1LL * triples * (cnt[0][i] + cnt[1][i])) % MOD;

            int contribution = (1LL << i) % MOD;
            contribution = (1LL * contribution * triples) % MOD;
            ans = (ans + contribution) % MOD;
        } else {
            int triples = (1LL << sz) % MOD;
            if (x[node] & (1LL << i))
                triples = (1LL * triples * cnt[0][i]) % MOD;
            else
                triples = (1LL * triples * cnt[1][i]) % MOD;

            int contribution = (1LL << i) % MOD;
            contribution = (1LL * contribution * triples) % MOD;
            ans = (ans + contribution) % MOD;
        }
    }

    return ans;
}

int count(int node) {
    int ans = count_single(node);
    for (int child: tree[node])
        ans = (ans + count(child)) % MOD;

    return ans;
}

void add_single(int node, int v) {
    for (int i = 0; i < MAX; i++) {
        if (x[node] & (1LL << i)) cnt[1][i] += v;
        else cnt[0][i] += v;
    }
}

void add(int node, int v) {
    add_single(node, v);
    for (int child: tree[node])
        add(child, v);
}

int solve(int node, bool keep = false) {
    int big = -1, mx = INT_MIN;
    for (int child: tree[node])
        if (nodes[child] > mx) {
            big = child;
            mx = nodes[child];
        }

    int ans = 0;
    for (int child: tree[node])
        if (child != big)
            ans = (ans + solve(child)) % MOD;

    if (big != -1) ans = (ans + solve(big, true)) % MOD;

    ans = (ans + count_single(node)) % MOD;
    add_single(node, 1);

    for (int child: tree[node])
        if (child != big) {
            ans = (ans + count(child)) % MOD;
            add(child, 1);
        }

    if (!keep) add(node, -1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<pair<int, llong>>());
    for (int i = 0; i < m; i++) {
        int u, v; llong t;
        cin >> u >> v >> t;

        g[u - 1].emplace_back(v - 1, t);
        g[v - 1].emplace_back(u - 1, t);
    }

    int ans = 0;
    memset(cnt, 0, sizeof cnt);
    tree.assign(n, vector<int>());
    vis.assign(n, 0);
    x.assign(n, 0LL);
    nodes.resize(n);

    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            sz = seen = 0;
            memset(basis, 0, sizeof basis);

            init(i);
            ans = (ans + solve(i)) % MOD;
        }

    cout << ans << "\n";
}