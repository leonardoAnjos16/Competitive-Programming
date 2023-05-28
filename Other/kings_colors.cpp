#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

vector<vector<int>> memo;

int count(int n, int k) {
    if (!n) return !k;
    if (!k) return 0;

    int &ans = memo[n][k];
    if (~ans) return ans;

    ans = (1LL * k * count(n - 1, k - 1)) % MOD;
    ans = (ans + (k - 1LL) * count(n - 1, k)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    memo.assign(n + 5, vector<int>(k + 5, -1));

    int ans = count(n, k);
    cout << ans << "\n";
}