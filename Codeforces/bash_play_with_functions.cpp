#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX_R = 1e6 + 5;
const int MAX_N = 1e6 + 5;
const int MAX_K = 25;
const int MOD = 1e9 + 7;

int memo[MAX_R][MAX_K];

int f(int r, int k) {
    if (!k) return 1;
    if (!r) return 2;

    int &ans = memo[r][k];
    if (~ans) return ans;

    ans = f(r, k - 1) + f(r - 1, k);
    if (ans > MOD) ans -= MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    memset(memo, -1, sizeof memo);

    int first_prime[MAX_N];
    for (int i = 1; i < MAX_N; i++)
        first_prime[i] = i;

    for (int i = 2; i < MAX_N; i++)
        if (first_prime[i] == i)
            for (int j = 2 * i; j < MAX_N; j += i)
                if (first_prime[j] == j)
                    first_prime[j] = i;

    while (q--) {
        int r, n;
        cin >> r >> n;

        map<int, int> cnt;
        while (n > 1) {
            cnt[first_prime[n]]++;
            n /= first_prime[n];
        }

        long ans = 1LL;
        for (auto [p, k]: cnt)
            ans = (ans * f(r, k)) % MOD;

        cout << ans << "\n";
    }
}