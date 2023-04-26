#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 6e5 + 5;
const int MOD = 998244353;

int facts[MAX], invs[MAX];

int comb(int n, int k) {
    int num = facts[n];
    int den = (1LL * invs[k] * invs[n - k]) % MOD;
    return (1LL * num * den) % MOD;
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    facts[0] = invs[0] = 1;
    for (int i = 1; i < MAX; i++) {
        facts[i] = (1LL * facts[i - 1] * i) % MOD;
        invs[i] = mod_mult_inv(facts[i], MOD);
    }

    int pows[MAX] = {1};
    for (int i = 1; i < MAX; i++)
        pows[i] = (2 * pows[i - 1]) % MOD;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> N(n + 1, 0);

    for (int i = 0; i <= m && 1LL * m * k + 1LL * i * k + m <= n; i++)
        N[m * k + i * k + m] = (((i & 1 ? -1LL : 1LL) * pows[m - i] * comb(m, i)) % MOD + MOD) % MOD;

    vector<int> D(n + 1);
    for (int i = 0; i <= n; i++)
        D[i] = comb(i + m, m);

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int aux = (1LL * N[i] * D[n - i]) % MOD;
        ans = (ans + aux) % MOD;
    }

    cout << ans << "\n";
}