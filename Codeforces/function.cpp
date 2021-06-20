#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e6 + 5;
const long MOD = 1e9 + 7;

vector<long> fact;

void get_coeffs(long a, long b, long &x, long &y) {
    if (!b) {
        x = 1LL;
        y = 0LL;
    } else {
        get_coeffs(b, a % b, x, y);
        long aux = x; x = y;
        y = aux - a / b * y;
    }
}

long mod_inverse(long a) {
    long x, y;
    get_coeffs(a, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}

long count(int n, int i) {
    long num = fact[n + 1];
    long den = (fact[i + 1] * fact[n - i]) % MOD;
    return (num * mod_inverse(den) - 1 + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact.assign(MAX, 1LL);
    for (int i = 2; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        long ans = 0LL;
        for (int i = 0; i < n; i++) {
            long a; cin >> a;
            ans = (ans + a * count(n, i)) % MOD;
        }

        cout << ans << "\n";
    }
}