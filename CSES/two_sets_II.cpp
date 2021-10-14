#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX_N = 505;
const int MAX_S = MAX_N * MAX_N / 2;

const long MMI2 = 5e8 + 4;
const int MOD = 1e9 + 7;

int memo[MAX_N][2 * MAX_S];

int count(int i, int diff = 0) {
    if (!i) return !diff;

    int idx = diff >= 0 ? diff : -diff + MAX_S;

    int &ans = memo[i][idx];
    if (~ans) return ans;

    ans = count(i - 1, diff + i);
    ans += count(i - 1, diff - i);
    ans %= MOD;

    return memo[i][diff] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    memset(memo, -1, sizeof memo);

    int ans = count(n);
    ans = (ans * MMI2) % MOD;
    cout << ans << "\n";
}