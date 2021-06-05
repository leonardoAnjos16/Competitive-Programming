#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

bitset<MAX> vis;
vector<vector<int>> g, tree;
vector<vector<long>> memo;

void get_tree(int v = 0) {
    vis[v] = true;
    for (auto u: g[v])
        if (!vis[u]) {
            get_tree(u);
            tree[v].push_back(u);
        }
}

long ways(int v = 0, int black = 0) {
    if (tree[v].empty()) return 2 - black;

    long &ans = memo[v][black];
    if (~ans) return ans;

    ans = 1LL;
    for (auto u: tree[v]) {
        ans *= ways(u);
        ans %= MOD;
    }

    if (!black) {
        long aux = 1LL;
        for (auto u: tree[v]) {
            aux *= ways(u, 1);
            aux %= MOD;
        }

        ans = (ans + aux) % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    g.assign(N, vector<int>());
    tree.assign(N, vector<int>());

    for (int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    get_tree();
    memo.assign(N + 5, vector<long>(2, -1LL));

    int ans = ways();
    cout << ans << "\n";
}