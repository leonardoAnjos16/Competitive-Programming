#include <bits/stdc++.h>

using namespace std;

#define long long long int

int r, c;
vector<vector<char>> grid;
vector<vector<bool>> vis;

bool touch_sides(int i, int j) {
    vis[i][j] = true;

    queue<pair<int, int>> aux;
    aux.emplace(i, j);

    bool ans = false;
    while (!aux.empty()) {
        auto p = aux.front(); aux.pop();
        i = p.first; j = p.second;

        ans |= !i || (i == r - 1) || !j || (j == c - 1);
        for (int k = -1; k <= 1; k++)
            for (int l = -1; l <= 1; l++)
                if ((k || l) && !(k && l)) {
                    int ni = i + k;
                    int nj = j + l;

                    if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == '.' && !vis[ni][nj]) {
                        vis[ni][nj] = true;
                        aux.emplace(ni, nj);
                    }
                }
    }

    return ans;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> r >> c;
    r <<= 1;
    c <<= 1;

    grid.assign(r, vector<char>(c));
    for (int i = 0; i < r; i += 2) {
        for (int j = 0; j < c; j += 2) {
            char ci; cin >> ci;
            if (ci == '.') {
                grid[i][j] = grid[i][j + 1] = '.';
                grid[i + 1][j] = grid[i + 1][j + 1] = '.';
            } else if (ci == '/') {
                grid[i][j] = grid[i + 1][j + 1] = '.';
                grid[i][j + 1] = grid[i + 1][j] = '#';
            } else {
                grid[i][j + 1] = grid[i + 1][j] = '.';
                grid[i][j] = grid[i + 1][j + 1] = '#';
            }
        }
    }

    vis.assign(r, vector<bool>(c, false));

    int ans = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (grid[i][j] == '.' && !vis[i][j] && !touch_sides(i, j))
                ans++;

    cout << ans << "\n";
}