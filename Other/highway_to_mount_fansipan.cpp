#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;
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
    if (k > n) return 0LL;
    return (facts[n] * mod_mult_inv(facts[n - k], MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < MAX; i++)
        facts[i] = (facts[i - 1] * i) % MOD;

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        vector<int> w(n);
        for (int i = 0; i < n; i++)
            cin >> w[i];

        int d; cin >> d;
        int cnt[30][60] = {0};

        vector<string> words(d);
        for (int i = 0; i < d; i++) {
            cin >> words[i];

            int m = words[i].size();
            cnt[words[i][0] - 'a'][m]++;
        }

        long ans = 0LL;
        for (int i = 0; i < d; i++) {
            int m = words[i].size();
            if (m == n) {
                map<pair<char, int>, int> curr;
                for (int j = 0; j < m; j++)
                    curr[make_pair(words[i][j], w[j])]++;

                long q = 1LL;
                for (auto [key, value]: curr) {
                    auto [letter, size] = key;
                    long aux = cnt[letter - 'a'][size];
                    if (words[i][0] == letter && m == size) aux--;
                    q = (q * comb(aux, value)) % MOD;
                }

                ans = (ans + q) % MOD;
            }
        }

        cout << ans << "\n";
    }
}