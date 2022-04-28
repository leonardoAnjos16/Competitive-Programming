#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> tree(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int four_children = tree[i].size();
        if (four_children < 4) continue;

        long four_comb = (four_children - 1LL) * (four_children - 2LL) * (four_children - 3LL) / 6LL;
        four_comb %= MOD;

        for (auto child: tree[i]) {
            int two_children = tree[child].size();
            if (two_children < 3) continue;

            long two_comb = (two_children - 1LL) * (two_children - 2LL) / 2LL;
            two_comb %= MOD;

            ans = (ans + four_comb * two_comb) % MOD;
        }
    }

    cout << ans << "\n";
}