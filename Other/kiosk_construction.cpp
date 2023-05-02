#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int h, w;
vector<vector<int>> a;
vector<vector<int>> dist, vis;

int get_dists(int target, int row, int col) {
    if (a[row][col] == target) return 0;
    if (vis[row][col] == 2) return dist[row][col];
    if (vis[row][col] == 1) return dist[row][col] = INF;

    vis[row][col] = 1;
    tuple<int, int, int, int> nxt = make_tuple(INF, INF, -1, -1);

    for (int drow = -1; drow <= 1; drow++)
        for (int dcol = -1; dcol <= 1; dcol++)
            if ((drow || dcol) && !(drow && dcol)) {
                int nrow = row + drow, ncol = col + dcol;
                if (nrow >= 0 && nrow < h && ncol >= 0 && ncol < w) {
                    int d1 = abs(target - a[nrow][ncol]);
                    int d2 = abs(a[row][col] - a[nrow][ncol]);
                    nxt = min(nxt, make_tuple(d1, d2, nrow, ncol));
                }
            }

    auto [_, __, nrow, ncol] = nxt;
    assert(nrow != -1 && ncol != -1);

    int d = get_dists(target, nrow, ncol);
    if (d >= INF) dist[row][col] = INF;
    else dist[row][col] = d + 1;

    vis[row][col] = 2;
    return dist[row][col];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;

    a.assign(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[i][j];

    vector<vector<int>> mx(h, vector<int>(w, INT_MIN));
    for (int i = 1; i <= h * w; i++) {
        dist.assign(h, vector<int>(w));
        vis.assign(h, vector<int>(w, 0));

        for (int j = 0; j < h; j++)
            for (int k = 0; k < w; k++)
                mx[j][k] = max(mx[j][k], get_dists(i, j, k));
    }

    int pos = -1, mn = INT_MAX;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (mx[i][j] < INF && mx[i][j] < mn) {
                pos = a[i][j];
                mn = mx[i][j];
            }

    if (pos == -1) cout << "impossible\n";
    else cout << pos << " " << mn << "\n";
}