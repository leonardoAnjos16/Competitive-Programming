#include <bits/stdc++.h>

using namespace std;

#define long long long int

int h, w;
vector<vector<int>> grid;
vector<vector<int>> dists;

void get_dists(int i, int j) {
    vector<vector<bool>> vis(h, vector<bool>(w, false));

    dists.assign(h, vector<int>(w, 0));
    dists[i][j] = -grid[i][j];

    priority_queue<pair<int, pair<int, int>>> heap;
    heap.emplace(-grid[i][j], make_pair(i, j));

    while (!heap.empty()) {
        pair<int, int> v = heap.top().second; heap.pop();
        if (vis[v.first][v.second]) continue;
        vis[v.first][v.second] = true;
        i = v.first; j = v.second;

        for (int k = -1; k <= 1; k++)
            for (int l = -1; l <= 1; l++) {
                int ni = i + k;
                int nj = j + l;

                if (ni >= 0 && ni < h && nj >= 0 && nj < w && grid[ni][nj] < 0 && !vis[ni][nj])
                    if (min(dists[i][j], min(-grid[i][j], -grid[ni][nj])) > dists[ni][nj]) {
                        dists[ni][nj] = min(dists[i][j], min(-grid[i][j], -grid[ni][nj]));
                        heap.emplace(dists[ni][nj], make_pair(ni, nj));
                    }
            }
    }

    /* for (int k = 0; k < h; k++) {
        for (int l = 0; l < w; l++)
            cout << dists[k][l] << " ";

        cout << "\n";
    } */
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;

    grid.assign(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];

    int i, j;
    cin >> i >> j;

    get_dists(--i, --j);

    long ans = 0LL;
    for (int k = 0; k < h; k++)
        for (int l = 0; l < w; l++)
            ans += dists[k][l];

    cout << ans << "\n";
}