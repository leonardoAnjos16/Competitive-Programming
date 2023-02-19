#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h, w;
    cin >> n >> m >> h >> w;

    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    int l = 1, r = n * m, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
                ps[i][j] += (g[i][j] <= mid ? -1 : 1);
            }

        bool possible = false;
        for (int i = h; i <= n && !possible; i++)
            for (int j = w; j <= m && !possible; j++)
                if (ps[i][j] - ps[i - h][j] - ps[i][j - w] + ps[i - h][j - w] <= 0)
                    possible = true;

        if (!possible) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}