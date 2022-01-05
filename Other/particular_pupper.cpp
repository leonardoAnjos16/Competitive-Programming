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

    int x, y, n;
    cin >> x >> y >> n;

    long ans = 0LL;
    for (int i = 0; i <= n; i++) {
        int sum = i * x + (n - i) * y;

        bool possible = true;
        while (sum && possible) {
            int d = sum % 10;
            sum /= 10;

            if (d != x && d != y)
                possible = false;
        }

        if (possible)
            ans = (ans + comb(n, i)) % MOD;
    }

    cout << ans << "\n";
}