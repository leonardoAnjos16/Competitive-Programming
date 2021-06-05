#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<vector<int>> g;
vector<int> memo;

int longest_path(int v) {
    int &ans = memo[v];
    if (~ans) return ans;

    ans = 0;
    for (auto u: g[v])
        ans = max(ans, 1 + longest_path(u));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M;

    g.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }

    memo.assign(N + 5, -1);

    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
        ans = max(ans, longest_path(i));

    cout << ans << "\n";
}