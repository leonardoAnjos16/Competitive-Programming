#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n;
vector<vector<int>> g;
vector<int> memo;

int max_condition(int v) {
    int &ans = memo[v];
    if (~ans) return ans;

    ans = 0;
    for (int i = 0; i < n; i++)
        if (g[v][i])
            ans = max(ans, max_condition(i) + g[v][i]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    g.assign(n, vector<int>(n, 0));
    while (m--) {
        int s, t, c;
        cin >> s >> t >> c;
        g[s - 1][t - 1] = max(g[s - 1][t - 1], c);
    }

    memo.assign(n + 5, -1);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, max_condition(i));

    cout << ans << "\n";
}