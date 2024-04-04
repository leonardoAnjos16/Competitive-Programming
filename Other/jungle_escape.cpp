#include <bits/stdc++.h>

using namespace std;

const int drow[4] = { -1, 0, 1, 0 };
const int dcol[4] = { 0, 1, 0, -1 };

int K, S, N, M;
vector<string> grid;
vector<vector<vector<int>>> dists;

void get_dists(int row, int col) {
    int max_steps = S / K;
    dists.assign(max_steps + 1, vector<vector<int>>(N, vector<int>(M, -1)));
    dists[0][row][col] = 0;

    queue<tuple<int, int, int>> q;
    q.emplace(0, row, col);

    while (!q.empty()) {
        int steps;
        tie(steps, row, col) = q.front();
        q.pop();

        if (steps + 1 > max_steps) continue;

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i], ncol = col + dcol[i];
            if (nrow < 0 || nrow >= N || ncol < 0 || ncol >= M || grid[nrow][ncol] == '#') continue;

            int nsteps = grid[nrow][ncol] != '$' ? steps + 1 : 0;
            if (dists[nsteps][nrow][ncol] != -1) continue;

            dists[nsteps][nrow][ncol] = dists[steps][row][col] + 1;
            q.emplace(nsteps, nrow, ncol);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> S >> N >> M;

    grid.resize(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    int srow = -1, scol = -1;
    int erow = -1, ecol = -1;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '@') srow = i, scol = j;
            else if (grid[i][j] == 'E') erow = i, ecol = j;
        }

    assert(srow != -1 && scol != -1);
    assert(erow != -1 && ecol != -1);

    get_dists(srow, scol);

    int ans = INT_MAX;
    for (int i = 0; i <= S / K; i++)
        if (dists[i][erow][ecol] != -1)
            ans = min(ans, K * dists[i][erow][ecol]);

    if (ans >= INT_MAX) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
}