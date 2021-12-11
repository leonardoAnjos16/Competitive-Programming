#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 55;

int cost[MAX][MAX][MAX][MAX] = {0}, memo[MAX][MAX][MAX];

int profit(int i, int j, int max_height) {
    if (i > j) return 0;

    int &ans = memo[i][j][max_height];
    if (~ans) return ans;

    ans = 0;
    for (int k = i; k <= j; k++)
        for (int h = 0; h <= max_height; h++)
            ans = max(ans, h * h - cost[i][j][k][h] + profit(i, k - 1, h) + profit(k + 1, j, h));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, m;
    cin >> n >> h >> m;

    while (m--) {
        int l, r, x, c;
        cin >> l >> r >> x >> c;

        for (int i = 0; i < l; i++)
            for (int j = r - 1; j < n; j++)
                for (int k = l - 1; k < r; k++)
                    for (int l = x + 1; l <= h; l++)
                        cost[i][j][k][l] += c;
    }

    memset(memo, -1, sizeof memo);

    int ans = profit(0, n - 1, h);
    cout << ans << "\n";
}