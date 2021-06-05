#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int H, W;
vector<string> a;
vector<vector<int>> memo;

int paths(int i = 0, int j = 0) {
    if (i + 1 == H && j + 1 == W) return 1;
    if (i >= H || j >= W || a[i][j] == '#') return 0;

    int &ans = memo[i][j];
    if (~ans) return ans;

    return ans = (paths(i, j + 1) + paths(i + 1, j)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> W;

    a.resize(H);
    for (int i = 0; i < H; i++)
        cin >> a[i];

    memo.assign(H + 5, vector<int>(W + 5, -1));

    int ans = paths();
    cout << ans << "\n";
}