#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;

int facts[MAX], invs[MAX];

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int a, int m) {
    return exp(a, m - 2);
}

int comb(int n, int k) {
    int num = facts[n];
    int den = (1LL * invs[n - k] * invs[k]) % MOD;
    return (1LL * num * den) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    facts[0] = invs[0] = 1;
    for (int i = 1; i < MAX; i++) {
        facts[i] = (1LL * facts[i - 1] * i) % MOD;
        invs[i] = mod_mult_inv(facts[i], MOD);
    }

    int N, K;
    cin >> N >> K;

    int ans = (comb(2 * N, N) - comb(2 * N, N + 1) + MOD) % MOD;
    ans = (1LL * ans * exp(K, N)) % MOD;
    cout << ans << "\n";
}