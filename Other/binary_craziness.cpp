#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int f(int d1, int d2) {
    int x = d1 ^ d2;
    int o = d1 | d2;
    int a = d1 & d2;

    int ans = (1LL * x * o) % MOD;
    ans = (1LL * ans * a) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> deg(n, 0), cnt(m + 1, 0);
    cnt[0] = n;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        cnt[deg[u - 1]++]--;
        cnt[deg[u - 1]]++;
        cnt[deg[v - 1]++]--;
        cnt[deg[v - 1]]++;
    }

    vector<pair<int, int>> degs;
    for (int i = 0; i <= m; i++)
        if (cnt[i])
            degs.emplace_back(i, cnt[i]);

    int ans = 0;
    for (auto [d1, c1]: degs)
        for (auto [d2, c2]: degs) {
            int aux = f(d1, d2);
            if (d2 > d1) {
                aux = (1LL * aux * c1) % MOD;
                aux = (1LL * aux * c2) % MOD;
                ans = (ans + aux) % MOD;
            } else if (d2 == d1) {
                int comb = (c1 * (c1 + 1LL) / 2LL) % MOD;
                aux = (aux * comb) % MOD;
                ans = (ans + aux) % MOD;
            }
        }

    cout << ans << "\n";
}