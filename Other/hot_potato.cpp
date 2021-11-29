#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 25;
const int MOD = 1e9 + 7;

int n; long invs[MAX];
vector<int> g, rg;
vector<vector<int>> memo;

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

int prob(int v, int vis) {
    if (!v) return vis == 1;

    int prev = rg[v] & vis;
    int cnt = __builtin_popcount(prev);
    if (!cnt) return 0;

    int &ans = memo[v][vis];
    if (~ans) return ans;

    ans = 0;
    for (int i = 0; i < n; i++)
        if (prev & (1 << i)) {
            cnt = __builtin_popcount(g[i] & ~vis) + 1;
            ans = (ans + (prob(i, vis ^ (1 << v)) * invs[cnt]) % MOD) % MOD;
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < MAX; i++)
        invs[i] = mod_mult_inv(i, MOD);

    cin >> n;

    g.assign(n, 0);
    rg.assign(n, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int connected; cin >> connected;
            if (connected) {
                g[i] |= 1 << j;
                rg[j] |= 1 << i;
            }
        }

    memo.assign(n, vector<int>(1 << n, -1));

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++) {
            bool possible = (j & (1 << i)) > 0;
            possible &= !__builtin_popcount(g[i] & ~j);

            if (possible)
                ans[i] = (ans[i] + prob(i, j)) % MOD;
        }
    
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}