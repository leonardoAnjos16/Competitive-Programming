#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 4e5 + 5;
const int MOD = 1e9 + 7;

int facts[MAX];

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

int comb(int n, int k) {
    if (k > n) return 0;

    int num = facts[n];
    int den = (1LL * facts[k] * (facts[n - k])) % MOD;
    return (num * mod_mult_inv(den, MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    facts[0] = 1;
    for (int i = 1; i < MAX; i++)
        facts[i] = (1LL * i * facts[i - 1]) % MOD;

    int T; cin >> T;
    while (T--) {
        int A, B, C, K, c;
        cin >> A >> B >> C >> K >> c;

        if (c + 2 > K) cout << "0\n";
        else {
            int aux = comb(A + B, K - c);
            aux = (aux - comb(A, K - c) + MOD) % MOD;
            aux = (aux - comb(B, K - c) + MOD) % MOD;

            int ans = (1LL * comb(C, c) * aux) % MOD;
            cout << ans << "\n";
        }
    }
}