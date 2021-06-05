#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    string s; cin >> s;

    vector<int> dp(N + 5, 0), sum(N + 5, 0);
    dp[1] = 1; sum[1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (s[i - 2] == '<') dp[j] = sum[j - 1];
            else dp[j] = (sum[i - 1] - sum[j - 1] + MOD) % MOD;
        }

        for (int j = 1; j <= i; j++)
            sum[j] = (sum[j - 1] + dp[j]) % MOD;
    }

    int ans = sum[N];
    cout << ans << "\n";
}