#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;
const int MOD = 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int mx_num[MAX], mx_mod[MOD];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        memset(mx_num, -1, sizeof mx_num);
        memset(mx_mod, -1, sizeof mx_mod);

        for (int j = 1; j < i; j++) {
            mx_mod[a[j] % MOD] = max(mx_mod[a[j] % MOD], dp[i][j]);
            mx_num[a[j]] = max(mx_num[a[j]], dp[i][j]);
        }

        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = max({ mx_num[a[j] - 1], mx_num[a[j] + 1], mx_mod[a[j] % MOD], dp[i][0] }) + 1;
            mx_mod[a[j] % MOD] = max(mx_mod[a[j] % MOD], dp[i][j]);
            mx_num[a[j]] = max(mx_num[a[j]], dp[i][j]);

            dp[j][i] = dp[i][j];
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";
}