#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;
const int MOD = 998244353;

vector<long> facts;

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
    den = mod_mult_inv(den, MOD);
    return (num * den) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    facts.assign(MAX, 1);
    for (int i = 1; i < MAX; i++) {
        facts[i] = facts[i - 1] * i;
        facts[i] %= MOD;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.rbegin(), a.rend());

        if (n == 1) cout << "1\n";
        else if (a[0] - a[1] >= 2) cout << "0\n";
        else {
            long ans = facts[n];

            int cnt = 1;
            while (cnt < n && a[cnt] == a[cnt - 1]) cnt++;

            if (cnt > 1) cout << ans << "\n";
            else {
                cnt = 0;
                for (int i = 1; i < n; i++)
                    if (a[i] == a[0] - 1) cnt++;

                for (int i = cnt; i < n; i++) {
                    long aux = (facts[i] * facts[n - i - 1]) % MOD;
                    aux = (aux * comb(n - cnt - 1, i - cnt)) % MOD;
                    ans = (ans - aux + MOD) % MOD;
                }

                cout << ans << "\n";
            }
        }
    }
}