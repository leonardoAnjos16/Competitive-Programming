#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 998244353;

vector<int> a, ps;
vector<vector<int>> memo;

int b(int i, int k) {
    if (!k) return ps[i + 1];
    if (!i) return 0;

    int &ans = memo[i][k];
    if (~ans) return ans;

    return ans = (b(i - 1, k) + b(i - 1, k - 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a1, x, y, m, k;
    cin >> n >> a1 >> x >> y >> m >> k;

    a.resize(n + 1);
    a[1] = a1;

    for (int i = 2; i <= n; i++)
        a[i] = (1LL * a[i - 1] * x + y) % m;

    ps.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        ps[i] = (ps[i - 1] + a[i]) % MOD;

    memo.assign(n + 5, vector<int>(k + 5, -1));

    llong ans = 0LL;
    for (int i = 1; i <= n; i++)
        ans ^= 1LL * b(i, k) * i;

    cout << ans << "\n";
}