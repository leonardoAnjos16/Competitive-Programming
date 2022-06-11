#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 123456789;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, S;
    cin >> L >> S;

    vector<int> dp(L, 0);
    dp[0] = 1;

    for (int i = 1; i < L; i++) {
        if (i <= S) dp[i] = (2 * dp[i - 1]) % MOD;
        else dp[i] = ((2 * dp[i - 1]) % MOD - dp[i - S - 1] + MOD) % MOD;
    }

    int ans = 0;
    for (int i = 1; i <= S; i++) {
        int aux = dp[L - i];
        if (L - i > 0)
            aux = (aux - dp[L - i - 1] + MOD) % MOD;
        
        aux = (1LL * i * aux) % MOD;
        ans = (ans + aux) % MOD;
    }

    cout << ans << "\n";
}