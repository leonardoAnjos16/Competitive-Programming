#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e9 + 5;

int x, n, m, t;
vector<vector<int>> g;
vector<pair<int, int>> rides;
vector<vector<int>> memo;

int euros(int v = 0, int time = 0) {
    if (time + rides[v].first > x) return INF;
    if (time + rides[v].first == x) return !v ? rides[0].second : INF;

    int &ans = memo[v][time];
    if (~ans) return ans;

    ans = euros(v, time + rides[v].first) + rides[v].second;
    for (auto u: g[v])
        ans = min(ans, euros(u, time + rides[v].first + t) + rides[v].second);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> n >> m >> t;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    rides.resize(n);
    for (int i = 0; i < n; i++) {
        int ti, pi;
        cin >> ti >> pi;
        rides[i] = make_pair(ti, pi);
    }

    memo.assign(n + 5, vector<int>(x + 5, -1));

    int ans = euros();
    if (ans < INF) cout << ans << "\n";
    else cout << "It is a trap.\n";
}