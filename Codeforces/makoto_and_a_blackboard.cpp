#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

void extended_euclidean(long a, long b, long &x, long &y) {
    if (!b) {
        x = 1LL;
        y = 0LL;
    } else {
        extended_euclidean(b, a % b, x, y);
        long aux = x; x = y;
        y = aux - a / b * y;
    }
}

long mod_mult_inv(long a, long m) {
    long x, y;
    extended_euclidean(a, m, x, y);
    return (x % m + m) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n; int k;
    cin >> n >> k;

    map<long, int> cnt;
    for (long i = 2LL; i * i <= n; i++)
        while (!(n % i)) cnt[i]++, n /= i;

    if (n > 1LL) cnt[n]++;

    int ans = 1;
    for (auto [p, c]: cnt) {
        int last = p % MOD;
        vector<int> sums(c + 1);
        vector<long> invs(c + 1);

        sums[0] = 1;
        invs[0] = 1LL;

        for (int i = 1; i <= c; i++) {
            invs[i] = mod_mult_inv(i + 1, MOD);
            sums[i] = (sums[i - 1] + last) % MOD;
            last = (1LL * last * p) % MOD;
        }

        for (int i = 0; i < k; i++) {
            vector<int> new_sums(c + 1);
            new_sums[0] = (invs[0] * sums[0]) % MOD;

            for (int j = 1; j <= c; j++) {
                last = (invs[j] * sums[j]) % MOD;
                new_sums[j] = (new_sums[j - 1] + last) % MOD;
            }

            sums = new_sums;
        }

        ans = (1LL * ans * last) % MOD;
    }

    cout << ans << "\n";
}