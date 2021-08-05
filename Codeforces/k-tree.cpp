#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int n, k, d;
vector<vector<int>> memo;

int paths(int used = 0, int sum = 0) {
    if (sum > n) return 0;
    if (sum == n) return used;

    int &ans = memo[used][sum];
    if (~ans) return ans;

    ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += paths(used || i >= d, sum + i);
        ans %= MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> d;

    memo.assign(2, vector<int>(n + 5, -1));

    int ans = paths();
    cout << ans << "\n";
}