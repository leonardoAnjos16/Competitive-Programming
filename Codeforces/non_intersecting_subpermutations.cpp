#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int sum(vector<int> &ps, int l, int r) {
    return (ps[r] - ps[l - 1] + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> ps(k + 1, 0);
    ps[k] = 1;

    for (int i = n - 1; i >= 0; i--) {
        vector<int> dp(k + 1);
        dp[0] = (1LL * k * sum(ps, 1, 1)) % MOD;

        for (int d = 1; d < k; d++) {
            dp[d] = (1LL * (k - d) * sum(ps, d + 1, d + 1)) % MOD;
            dp[d] = (dp[d] + sum(ps, 1, d)) % MOD;
        }

        dp[k] = (dp[0] + k) % MOD;
        ps[0] = dp[0];

        for (int j = 0; j <= k; j++)
            cout << dp[j] << " ";

        cout << "\n";

        for (int j = 1; j <= k; j++)
            ps[j] = (ps[j - 1] + dp[j]) % MOD;
    }

    int ans = ps[0];
    cout << ans << "\n";
}