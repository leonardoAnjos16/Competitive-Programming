#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e5 + 5;
const int MOD = 1e9 + 7;

int invs[MAX];

int interpolate(int x, vector<int> &ys) {
    int n = (int) ys.size() - 1;
    vector<int> pnum(n + 2);
    vector<int> snum(n + 2);

    pnum[0] = 1;
    for (int i = 1; i <= n; i++)
        pnum[i] = (((1LL * pnum[i - 1] * (x - i)) % MOD) + MOD) % MOD;

    snum[n + 1] = 1;
    for (int i = n; i > 0; i--)
        snum[i] = (((1LL * snum[i + 1] * (x - i)) % MOD) + MOD) % MOD;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int num = (1LL * pnum[i - 1] * snum[i + 1]) % MOD;
        int den = (1LL * invs[n - i] * invs[i - 1]) % MOD;
        if ((n - i) & 1) den = (MOD - den) % MOD;

        int add = (1LL * num * den) % MOD;
        add = (1LL * add * ys[i]) % MOD;
        ans = (ans + add) % MOD;
    }

    return ans;
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

    int fact = invs[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact = (1LL * fact * i) % MOD;
        invs[i] = mod_mult_inv(fact, MOD);
    }

    int n, k;
    cin >> n >> k;

    int sum = 0;
    vector<int> ys(2 * k + 3);

    for (int i = 1; i <= 2 * k + 2; i++) {
        int curr = (1LL * exp(i, k) * exp(n - i + 1, k)) % MOD;
        sum = (sum + curr) % MOD;
        ys[i] = sum;
    }

    int num = interpolate(n, ys);

    sum = 0;
    ys.resize(k + 3);

    for (int i = 1; i <= k + 2; i++) {
        int curr = exp(i, k);
        sum = (sum + curr) % MOD;
        ys[i] = sum;
    }

    int den = interpolate(n, ys);

    int ans = (1LL * num * mod_mult_inv(den, MOD)) % MOD;
    cout << ans << "\n";
}