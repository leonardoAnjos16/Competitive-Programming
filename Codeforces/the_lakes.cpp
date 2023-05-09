#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n, m;
vector<vector<int>> a;
vector<vector<bool>> vis;

int volume(int row, int col) {
    if (vis[row][col]) return 0;

    vis[row][col] = true;
    int ans = a[row][col];

    for (int drow = -1; drow <= 1; drow++)
        for (int dcol = -1; dcol <= 1; dcol++)
            if ((drow || dcol) && !(drow && dcol)) {
                int nrow = row + drow, ncol = col + dcol;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && a[row][col])
                    ans += volume(nrow, ncol);
            }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> m;

        a.assign(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        int ans = 0;
        vis.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j])
                    ans = max(ans, volume(i, j));

        cout << ans << "\n";
    }
}