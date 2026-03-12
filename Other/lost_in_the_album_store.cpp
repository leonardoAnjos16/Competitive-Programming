#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> r(n + 1, vector<int>(m + 1, 0));
    vector<vector<llong>> psr(n + 1, vector<llong>(m + 1, 0LL));
    vector<vector<llong>> psc(n + 1, vector<llong>(m + 1, 0LL));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> r[i][j];
            psr[i][j] = psr[i][j - 1] + r[i][j];
            psc[i][j] = psc[i - 1][j] + r[i][j];
        }

    vector<vector<llong>> dp(n + 1, vector<llong>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) dp[i][j] = 0LL;
            else if (i == 1) dp[i][j] = dp[i][j - 1] + psr[i][j - 2] * psr[i][j - 2];
            else if (j == 1) dp[i][j] = dp[i - 1][j] + psc[i - 2][j] * psc[i - 2][j];
            else dp[i][j] = min(dp[i - 1][j] + psc[i - 2][j] * psc[i - 2][j], dp[i][j - 1] + psr[i][j - 2] * psr[i][j - 2]);
        }

    llong ans = dp[n][m];
    cout << ans << "\n";
}