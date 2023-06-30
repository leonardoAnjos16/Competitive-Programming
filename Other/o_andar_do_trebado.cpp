#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e4 + 5;

int facts[MAX], invs[MAX];

int exp(int a, int n, int MOD) {
    if (!n) return 1;

    int ans = exp(a, n >> 1, MOD);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int x, int MOD) {
    return exp(x, MOD - 2, MOD);
}

int comb(int n, int k, int MOD) {
    int num = facts[n];
    int den = (1LL * invs[k] * invs[n - k]) % MOD;
    return (1LL * num * den) % MOD;
}

int coeff(int k, int n, int MOD) {
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i % 3) continue;

        int a = comb(k, i / 3, MOD);
        if (i & 1) a = (MOD - a) % MOD;

        int b = comb(n - i + k - 1, k - 1, MOD);
        ans = (ans + 1LL * a * b) % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, P;
    cin >> K >> P;

    facts[0] = invs[0] = 1;
    for (int i = 1; i < MAX; i++) {
        facts[i] = (1LL * facts[i - 1] * i) % P;
        invs[i] = mod_mult_inv(facts[i], P);
    }

    int ans = coeff(K, K, P);
    ans = (1LL * ans * ans) % P;

    for (int i = 1; i < K; i++) {
        int aux = coeff(K - i, K - i, P);
        aux = (1LL * aux * aux) % P;
        aux = (1LL * aux * comb(K, i, P)) % P;

        if (i & 1) ans = (ans - aux + P) % P;
        else ans = (ans + aux) % P;
    }

    if (K & 1) ans = (ans - 1 + P) % P;
    else ans = (ans + 1) % P;

    cout << ans << "\n";
}