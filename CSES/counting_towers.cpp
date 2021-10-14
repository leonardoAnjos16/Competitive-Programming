#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;

int memo[MAX][3];

int towers(int h, int row_span) {
    if (h == 1) return 1;

    int &ans = memo[h][row_span];
    if (~ans) return ans;

    ans = (towers(h - 1, 1) + towers(h - 1, 2)) % MOD;
    if (row_span == 1) {
        ans += towers(h - 1, 1);
        ans %= MOD;

        ans += towers(h - 1, 1);
        ans %= MOD;

        ans += towers(h - 1, 1);
        ans %= MOD;
    } else {
        ans += towers(h - 1, 2);
        ans %= MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof memo);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int ans = (towers(n, 1) + towers(n, 2)) % MOD;
        cout << ans << "\n";
    }
}