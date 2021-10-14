#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= h[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
        }

    int ans = dp[n][x];
    cout << ans << "\n";
}