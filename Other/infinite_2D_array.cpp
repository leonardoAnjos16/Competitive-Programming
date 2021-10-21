#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e6 + 5;
const int MOD = 1e9 + 7;

long facts[MAX] = {1LL};

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

long comb(int n, int k) {
    long num = facts[n];
    long den = (facts[k] * facts[n - k]) % MOD;
    return (num * mod_mult_inv(den, MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < MAX; i++)
        facts[i] = (facts[i - 1] * i) % MOD;
    
    long fibs[MAX] = {0LL};
    fibs[1] = 1LL;

    for (int i = 2; i < MAX; i++)
        fibs[i] = (fibs[i - 1] + fibs[i - 2]) % MOD;

    int x, y;
    cin >> x >> y;

    long ans = 0LL, last = 0LL;
    for (int i = x; i > 0; i--) {
        long dist = x - i + y;
        long cnt = comb(dist, x - i);
        long aux = (cnt - last + MOD) % MOD;

        ans = (ans + aux * fibs[i]) % MOD;
        last = cnt;
    }

    last = 0LL;
    for (int i = y; i > 0; i--) {
        long dist = x + y - i;
        long cnt = comb(dist, y - i);
        long aux = (cnt - last + MOD) % MOD;

        ans = (ans + aux * fibs[i]) % MOD;
        last = cnt;
    }

    cout << ans << "\n";
}