#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> memo;

int sequences(int i = 0, int last = 0) {
    if (i >= n) return 1;

    int &ans = memo[i][last];
    if (~ans) return ans;

    ans = 0;
    for (int j = last + 1; j <= m; j++)
        ans = (ans + sequences(i + 1, j)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;

    memo.assign(n + 5, vector<int>(m + 5, -1));

    int ans = sequences();
    cout << ans << "\n";
}