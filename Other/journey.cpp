#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 505;

int n, m;
vector<string> grid;
vector<vector<int>> dists;

void get_dists() {
    dists.assign(m, vector<int>(n, -1));
    vector<bitset<MAX>> vis(m, bitset<MAX>());

    queue<pair<int, int>> aux;
    aux.emplace(0, 0);

    dists[0][0] = 0;
    vis[0][0] = true;

    while (!aux.empty()) {
        int i = aux.front().first;
        int j = aux.front().second;
        aux.pop();

        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {
                if ((k && l) || !(k || l)) continue;

                int ni = i + k;
                int nj = j + l;

                if (ni < 0 || ni >= m) continue;
                if (nj < 0 || nj >= n) continue;
                if (grid[ni][nj] == '#') continue;

                if (!vis[ni][nj]) {
                    vis[ni][nj] = true;
                    aux.emplace(ni, nj);
                    dists[ni][nj] = dists[i][j] + 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    cin >> a >> b;

    grid.resize(m);
    for (int i = 0; i < m; i++)
        cin >> grid[i];

    get_dists();

    int dist = dists[m - 1][n - 1];
    if (dist < 0) cout << "IMPOSSIBLE\n";
    else {
        int ans = dist / 2 * a;
        dist -= dist / 2;
        ans += dist * b;
        cout << ans << "\n";
    }
}