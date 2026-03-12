#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 5e3 + 5;
const int MOD = 1e9 + 7;

int invs[MAX];

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int fact = invs[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact = (1LL * fact * i) % MOD;
        invs[i] = mod_mult_inv(fact, MOD);
    }

    int N, R;
    cin >> N >> R;

    vector<int> p(N);
    for (int i = 0; i < N; i++)
        cin >> p[i];

    vector<int> ys(3, 0);
    ys[1] = 1;
    ys[2] = 2;

    int mn = INT_MIN;
    for (int i = N - 1; i >= 0; i--) {
        mn = max(mn, p[i]);
        int rem = interpolate(mn - 1, ys);
        ys.push_back(interpolate(N - i + 2, ys));

        for (int j = 1; j <= N - i + 2; j++) {
            ys[j] = (ys[j] + ys[j - 1]) % MOD;
            ys[j] = (ys[j] - rem + MOD) % MOD;
        }
    }

    if (R < mn) cout << "0\n";
    else {
        int ans = interpolate(R, ys);
        ans = (ans - interpolate(R - 1, ys) + MOD) % MOD;
        cout << ans << "\n";
    }
}