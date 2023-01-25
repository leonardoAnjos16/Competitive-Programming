#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int fact[MAX] = {1, 1}, sum[MAX] = {0};
    for (int i = 2; i < MAX; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        sum[i] = (1LL * sum[i - 1] * i) % MOD;
        int aux = ((i - 1LL) * i / 2LL) % MOD;
        aux = (1LL * aux * fact[i - 1]) % MOD;
        sum[i] = (sum[i] + aux) % MOD;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int ans = (2LL * sum[n]) % MOD;
        int aux = ((n - 1LL) * n / 2LL) % MOD;
        aux = (1LL * aux * fact[n]) % MOD;
        ans = (ans + aux) % MOD;
        cout << ans << "\n";
    }
}