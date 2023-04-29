#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> L(K), R(K);
    for (int i = 0; i < K; i++)
        cin >> L[i] >> R[i];

    vector<int> dp(N + 1, 0);
    dp[1] = 1;

    for (int i = 1; i < N; i++) {
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
        for (int j = 0; j < K; j++) {
            if (i + L[j] <= N) dp[i + L[j]] = (dp[i + L[j]] + dp[i]) % MOD;
            if (i + R[j] + 1 <= N) dp[i + R[j] + 1] = (dp[i + R[j] + 1] - dp[i] + MOD) % MOD;
        }
    }

    int ans = dp[N];
    cout << ans << "\n";
}