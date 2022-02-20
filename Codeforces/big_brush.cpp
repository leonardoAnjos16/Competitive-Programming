#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<tuple<int, int, int>> ans;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1]) {
                q.emplace(i - 1, j - 1);
                vis[i - 1][j - 1] = true;
                ans.emplace_back(i, j, a[i][j]);
                a[i - 1][j - 1] = a[i - 1][j] = a[i][j - 1] = a[i][j] = 0;
            }

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = r - 1; i <= r + 1; i++)
            for (int j = c - 1; j <= c + 1; j++) {
                if (i < 0 || i + 1 >= n || j < 0 || j + 1 >= m || vis[i][j]) continue;

                int color = a[i][j];
                if (!color) color = a[i][j + 1];
                if (!color) color = a[i + 1][j];
                if (!color) color = a[i + 1][j + 1];
                if (!color) continue;

                if (a[i][j] && a[i][j] != color) continue;
                if (a[i][j + 1] && a[i][j + 1] != color) continue;
                if (a[i + 1][j] && a[i + 1][j] != color) continue;
                if (a[i + 1][j + 1] && a[i + 1][j + 1] != color) continue;

                q.emplace(i, j);
                vis[i][j] = true;
                ans.emplace_back(i + 1, j + 1, color);
                a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;
            }
    }

    bool possible = true;
    for (int i = 0; i < n && possible; i++)
        for (int j = 0; j < m && possible; j++)
            if (a[i][j]) possible = false;

    if (!possible) cout << "-1\n";
    else {
        int q = ans.size();
        cout << q << "\n";

        reverse(ans.begin(), ans.end());
        for (auto [i, j, c]: ans)
            cout << i << " " << j << " " << c << "\n";
    }
}