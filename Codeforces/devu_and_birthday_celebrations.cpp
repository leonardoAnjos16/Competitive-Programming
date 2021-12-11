#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

long facts[MAX], invs[MAX];
vector<int> divs[MAX];
int memo[MAX], fvis[MAX];

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
    return (((facts[n] * invs[k]) % MOD) * invs[n - k]) % MOD;
}

int ways(int n, int f) {
    if (n < f) return 0;
    if (n == f) return 1;

    if (fvis[n] == f)
        return memo[n];

    fvis[n] = f;
    int ans = comb(n - 1, f - 1);

    for (auto g: divs[n])
        ans = (ans - ways(n / g, f) + MOD) % MOD;

    return memo[n] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    facts[0] = invs[0] = 1LL;
    for (int i = 1; i < MAX; i++) {
        facts[i] = (facts[i - 1] * i) % MOD;
        invs[i] = mod_mult_inv(facts[i], MOD);
    }

    for (int i = 1; i < MAX; i++) {
        for (int j = 2; j * j <= i; j++)
            if (!(i % j)) {
                divs[i].push_back(j);
                if (j * j < i)
                    divs[i].push_back(i / j);
            }

        divs[i].push_back(i);
        sort(divs[i].begin(), divs[i].end());
    }

    memset(memo, -1, sizeof memo);
    memset(fvis, -1, sizeof fvis);

    int q; cin >> q;
    while (q--) {
        int n, f;
        cin >> n >> f;

        int ans = ways(n, f);
        cout << ans << "\n";
    }
}