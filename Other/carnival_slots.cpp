#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("balls.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int r, c;
        cin >> r >> c;

        vector<int> b(c);
        for (int i = 0; i < c; i++)
            cin >> b[i];

        vector<string> grid(r);
        for (int i = 0; i < r; i++)
            cin >> grid[i];

        vector<int> s(c);
        for (int i = 0; i < c; i++)
            cin >> s[i];

        vector<vector<int>> dp(r + 1, vector<int>(c + 2, 0));
        for (int i = 1; i <= c; i++)
            dp[r][i] = s[i - 1];

        for (int i = r - 1; i >= 0; i--)
            for (int j = 1; j <= c; j++) {
                if (grid[i][j - 1] == '.') dp[i][j] = dp[i + 1][j];
                else if (grid[i][j] == '\\') {
                    dp[i][j] = dp[i + 1][j + 1];
                    if (dp[i + 1][j - 1] >= dp[i][j])
                        dp[i][j] = dp[i + 1][j - 1];

                    if (dp[i + 1][j] >= dp[i][j])
                        dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i + 1][j] >= dp[i][j])
                        dp[i][j] = dp[i + 1][j];

                    if (dp[i + 1][j + 1] >= dp[i][j])
                        dp[i][j] = dp[i + 1][j + 1];
                }
            }

        long ans = 0LL;
        for (int i = 0; i < c; i++)
            ans += 1LL * b[i] * dp[0][i + 1];

        cout << ans << "\n";
    }
}