#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<int> pots;
vector<vector<int>> tree;
bitset<MAX> vis;

long ways(int v = 0) {
    vis[v] = true;

    long ans = 1LL;
    int leaves = 0, internal = 0;

    for (auto u: tree[v]) {
        if (vis[u]) continue;

        if (tree[u].size() < 2) leaves++;
        else {
            internal++;
            ans *= ways(u);
            ans %= MOD;
        }
    }

    if (leaves) ans = (ans * pots[leaves - 1]) % MOD;
    else if (!(internal & 1)) ans = 0LL;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pots.assign(MAX, 1);
    for (int i = 1; i < MAX; i++) {
        pots[i] = pots[i - 1] * 2;
        pots[i] %= MOD;
    }

    int n; cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;

        tree[x - 1].push_back(y - 1);
        tree[y - 1].push_back(x - 1);
    }

    int ans = ways();
    cout << ans << "\n";
}