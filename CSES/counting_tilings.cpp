#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int n, m;
vector<vector<vector<int>>> memo;

int ways(int row = 0, int col = 0, int last = 0) {
    if (col >= m) return !last;
    if (row >= n) return ways(0, col + 1, last);
    if (last & (1 << row)) return ways(row + 1, col, last ^ (1 << row));

    int &ans = memo[row][col][last];
    if (~ans) return ans;

    ans = ways(row + 1, col, last | (1 << row));
    if (row + 1 < n && !(last & (1 << (row + 1))))
        ans = (ans + ways(row + 2, col, last)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    memo.assign(n + 5, vector<vector<int>>(m + 5, vector<int>(1 << n, -1)));

    int ans = ways();
    cout << ans << "\n";
}