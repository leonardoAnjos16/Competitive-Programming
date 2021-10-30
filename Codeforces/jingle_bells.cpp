#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

vector<vector<pair<int, int>>> tree;
vector<vector<long>> memo;

long ways(int parent_color = 6, int v = 0, int p = -1) {
    int children = (int) tree[v].size();
    if (children <= 1 && ~p) return 1LL;

    long &ans = memo[parent_color][v];
    if (~ans) return ans;

    ans = 0LL;
    for (int i = 1; i < (1 << 5); i++) {
        if (__builtin_popcount(i) != children) continue;

        vector<int> colors;
        for (int j = 0; j < 5; j++)
            if (i & (1 << j))
                colors.push_back(j + 1);

        do {
            long cnt = 1LL;
            bool possible = true;

            for (int j = 0; j < children && possible; j++) {
                auto [u, c] = tree[v][j];
                if (u == p && colors[j] != parent_color) possible = false;
                else if (u != p) {
                    if (c && c != colors[j]) possible = false;
                    else cnt = (cnt * ways(colors[j], u, v)) % MOD;
                }
            }

            if (!possible) continue;
            ans = (ans + cnt) % MOD;
        } while (next_permutation(colors.begin(), colors.end()));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    tree.assign(N, vector<pair<int, int>>());
    for (int i = 1; i < N; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        tree[u - 1].emplace_back(v - 1, c);
        tree[v - 1].emplace_back(u - 1, c);
    }

    memo.assign(10, vector<long>(N + 5, -1LL));

    if (N == 1) cout << "1\n";
    else {
        long ans = ways();
        cout << ans << "\n";
    }
}