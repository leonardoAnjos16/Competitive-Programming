#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

string K; int D, n;
vector<vector<vector<int>>> memo;

int solve(int i = 0, int tight = 1, int m = 0) {
    if (i >= n) return !m;

    int &ans = memo[i][tight][m];
    if (~ans) return ans;

    ans = 0;
    for (int j = 0; j <= (tight ? K[i] - '0' : 9); j++) {
        ans += solve(i + 1, tight && (j == K[i] - '0'), (m + j) % D);
        ans %= MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> D;
    n = K.size();

    memo.assign(n + 5, vector<vector<int>>(2, vector<int>(D + 5, -1)));

    int ans = (solve() - 1 + MOD) % MOD;
    cout << ans << "\n";
}