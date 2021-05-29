#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<long>> dp(n + 1, vector<long>(n + 1, -INF));
    for (int i = 0; i <= n; i++) dp[i][0] = 0LL;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            long aux = dp[i - 1][j - 1] + a[i];

            dp[i][j] = dp[i - 1][j];
            if (aux >= 0LL)
                dp[i][j] = max(dp[i][j], aux);

            if (dp[i][j] >= 0LL) ans = max(ans, j);
        }

    cout << ans << "\n";
}