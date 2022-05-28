#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;
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
    int den = (1LL * invs[k] * invs[n - k]) % MOD;
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

    int t; cin >> t;
    while (t--) {
        int N, K, X;
        cin >> N >> K >> X;

        if (2 * X > K || K - 2 * X > N - X) cout << "0\n";
        else {
            int ans = comb(N, X);
            ans = (1LL * ans * comb(N - X, K - 2 * X)) % MOD;
            ans = (1LL * ans * exp(2, K - 2 * X)) % MOD;
            cout << ans << "\n";
        }
    }
}