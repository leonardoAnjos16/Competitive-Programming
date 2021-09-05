#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int exp(int a, int n) {
    if (!n) return 1LL;

    long ans = exp(a, n >> 1LL);
    ans = (ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (ans * a) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("exor.in", "r", stdin);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        long ans = (exp(2, n + 1) - 1 + MOD) % MOD;
        ans = (ans * exp(2, n)) % MOD;
        cout << ans << "\n";
    }
}