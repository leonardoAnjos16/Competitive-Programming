#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int get_sum(vector<int> &sum, int l, int r) {
    int ans = sum[r];
    if (l) ans -= sum[l - 1];
    return (ans + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    vector<int> dp(K + 5, 0), sum(K + 5, 0);
    for (int i = 0; i <= a[1]; i++) dp[i] = 1;

    sum[0] = dp[0];
    for (int i = 1; i <= K; i++) {
        sum[i] = sum[i - 1] + dp[i];
        sum[i] %= MOD;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= K; j++)
            dp[j] = get_sum(sum, j - min(a[i], j), j);

        sum[0] = dp[0];
        for (int j = 1; j <= K; j++) {
            sum[j] = sum[j - 1] + dp[j];
            sum[j] %= MOD;
        }
    }

    int ans = dp[K];
    cout << ans << "\n";
}