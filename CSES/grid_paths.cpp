#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int n;
vector<string> grid;
vector<vector<int>> memo;

int paths(int i = 0, int j = 0) {
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '*') return 0;
    if (i + 1 >= n && j + 1 >= n) return 1;

    int &ans = memo[i][j];
    if (~ans) return ans;

    return ans = (paths(i + 1, j) + paths(i, j + 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    memo.assign(n + 5, vector<int>(n + 5, -1));

    if (grid[0][0] == '*') cout << "0\n";
    else {
        int ans = paths();
        cout << ans << "\n";
    }
}