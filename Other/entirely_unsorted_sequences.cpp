#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 5e3 + 5;
const int MOD = 1e9 + 9;

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

    int facts[MAX], invs[MAX];
    facts[0] = invs[0] = 1;

    for (int i = 1; i < MAX; i++) {
        facts[i] = (1LL * facts[i - 1] * i) % MOD;
        invs[i] = mod_mult_inv(facts[i], MOD);
    }

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a.begin() + 1, a.end());

    int prod = 1;
    map<int, int> cnt;
    cnt[a[1]]++;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 2; i <= n; i++) {
        prod = (1LL * prod * facts[cnt[a[i]]++]) % MOD;
        prod = (1LL * prod * invs[cnt[a[i]]]) % MOD;

        int remove = 0;
        int curr_prod = prod;
        map<int, int> curr_cnt = cnt;

        for (int j = 1; j <= i; j++) {
            curr_prod = (1LL * curr_prod * facts[curr_cnt[a[j]]--]) % MOD;
            curr_prod = (1LL * curr_prod * invs[curr_cnt[a[j]]]) % MOD;

            int add = (1LL * dp[j - 1] * facts[i - j]) % MOD;
            add = (1LL * add * curr_prod) % MOD;
            remove = (remove + add) % MOD;
        }

        dp[i] = (1LL * facts[i] * prod) % MOD;
        dp[i] = (dp[i] - remove + MOD) % MOD;
    }

    int ans = dp[n];
    cout << ans << "\n";
}