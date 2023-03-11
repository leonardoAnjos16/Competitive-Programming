#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

int N, C;
vector<vector<pair<int, int>>> g;
vector<vector<int>> memo;
vector<int> cost;

int get_cost(int v) {
    int &ans = cost[v];
    if (~ans) return ans;

    ans = 0;
    for (auto [u, c]: g[v]) {
        ans += get_cost(u) + c;
        if (ans > C) break;
    }

    return ans;
}

int count(int i = 0, int sum = 0) {
    if (sum > C) return 0;
    if (i >= N) return 1;

    int &ans = memo[i][sum];
    if (~ans) return ans;

    ans = count(i + 1, sum);
    ans = (ans + count(i, sum + cost[i])) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M >> C;

    g.assign(N, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[v - 1].emplace_back(u - 1, c);
    }

    cost.assign(N, -1);
    cost[0] = 1;

    for (int i = 0; i < N; i++)
        get_cost(i);

    memo.assign(N + 5, vector<int>(C + 5, -1));

    int ans = (count() - 1 + MOD) % MOD;
    cout << ans << "\n";
}