#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5 + 5;
const int MOD = 998244353;

int facts[MAX], invs[MAX];

int pow(int a, int n) {
    if (!n) return 1;

    int ans = pow(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int a, int m) {
    return pow(a, m - 2);
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

    int n; cin >> n;

    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    int ans = 1;
    for (int i = 0; i < n; i += 3) {
        int cnt = w[i] <= w[i + 1] && w[i] <= w[i + 2];
        cnt += w[i + 1] <= w[i] && w[i + 1] <= w[i + 2];
        cnt += w[i + 2] <= w[i] && w[i + 2] <= w[i + 1];

        ans = (1LL * ans * cnt) % MOD;
    }

    ans = (1LL * ans * comb(n / 3, n / 6)) % MOD;
    cout << ans << "\n";
}