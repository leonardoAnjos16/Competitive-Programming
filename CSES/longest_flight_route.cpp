#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e6 + 5;

int n;
vector<vector<int>> g;
vector<int> memo, nxt;

int longest(int v = 0) {
    if (v + 1 == n) return 0;

    int &ans = memo[v];
    if (~ans) return ans;

    ans = -INF;
    for (int u: g[v])
        if (longest(u) + 1 > ans) {
            nxt[v] = u;
            ans = longest(u) + 1;
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }

    memo.assign(n, -1);
    nxt.assign(n, -1);

    int ans = longest() + 1;
    if (ans <= 0) cout << "IMPOSSIBLE\n";
    else {
        cout << ans << "\n";

        int v = 0;
        while (nxt[v] != -1) {
            cout << (v + 1) << " ";
            v = nxt[v];
        }

        assert(v + 1 == n);
        cout << (v + 1) << "\n";
    }
}