#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 25;
const int MOD = 1e9 + 7;

long invs[MAX];

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

map<long, long> mult(map<long, long> &p, map<long, long> &q) {
    map<long, long> ans;
    for (auto [i, a]: p)
        for (auto [j, b]: q)
            ans[i + j] = (ans[i + j] + a * b) % MOD;

    return ans;
}

long comb(long n, long k) {
    assert(n - k < MAX);

    long ans = 1LL;
    for (long i = k + 1LL; i <= n; i++)
        ans = (ans * (i % MOD)) % MOD;

    return (ans * invs[n - k]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long fact = 1LL;
    invs[0] = 1LL;

    for (int i = 1; i < MAX; i++) {
        fact = (fact * i) % MOD;
        invs[i] = mod_mult_inv(fact, MOD);
    }

    int n; long s;
    cin >> n >> s;

    map<long, long> p;
    p[0LL] = 1LL;

    for (int i = 0; i < n; i++) {
        long f; cin >> f;

        map<long, long> q;
        q[0LL] = 1LL;
        q[f + 1LL] = MOD - 1LL;

        p = mult(p, q);
    }

    long ans = 0LL;
    for (auto [i, a]: p) {
        if (i > s) break;
        long b = comb(n + s - i - 1LL, s - i);
        ans = (ans + a * b) % MOD;
    }

    cout << ans << "\n";
}