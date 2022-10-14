#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

int W, H, N;
vector<vector<vector<char>>> office;
vector<tuple<int, int, int>> stairs;
vector<vector<vector<llong>>> sum;

void update_sum(int floor, int row, int col) {
    vector<vector<vector<int>>> dists(N, vector<vector<int>>(H, vector<int>(W, INF)));
    dists[floor][row][col] = 0;

    queue<tuple<int, int, int>> q;
    q.emplace(floor, row, col);

    while (!q.empty()) {
        tie(floor, row, col) = q.front();
        q.pop();

        if (office[floor][row][col] == 's') {
            for (auto [sfloor, srow, scol]: stairs)
                for (int drow = -1; drow <= 1; drow++)
                    for (int dcol = -1; dcol <= 1; dcol++)
                        if ((drow || dcol) && !(drow && dcol)) {
                            int nrow = srow + drow, ncol = scol + dcol;
                            if (nrow >= 0 && nrow < H && ncol >= 0 && ncol < W && dists[sfloor][nrow][ncol] >= INF)
                                if (office[sfloor][nrow][ncol] != 'w' && office[sfloor][nrow][ncol] != 'o') {
                                    q.emplace(sfloor, nrow, ncol);
                                    dists[sfloor][nrow][ncol] = dists[floor][row][col] + 1;
                                }
                        }
        } else {
            for (int drow = -1; drow <= 1; drow++)
                for (int dcol = -1; dcol <= 1; dcol++)
                    if ((drow || dcol) && !(drow && dcol)) {
                        int nrow = row + drow, ncol = col + dcol;
                        if (nrow >= 0 && nrow < H && ncol >= 0 && ncol < W && dists[floor][nrow][ncol] >= INF)
                            if (office[floor][nrow][ncol] != 'w' && office[floor][nrow][ncol] != 'o') {
                                q.emplace(floor, nrow, ncol);
                                dists[floor][nrow][ncol] = dists[floor][row][col] + 1;
                            }
                    }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < H; j++)
            for (int k = 0; k < W; k++)
                sum[i][j][k] += dists[i][j][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W >> H >> N;

    office.assign(N, vector<vector<char>>(H, vector<char>(W)));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < H; j++)
            for (int k = 0; k < W; k++) {
                cin >> office[i][j][k];
                if (office[i][j][k] == 's')
                    stairs.emplace_back(i, j, k);
            }

    sum.assign(N, vector<vector<llong>>(H, vector<llong>(W, 0LL)));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < H; j++)
            for (int k = 0; k < W; k++)
                if (office[i][j][k] == 'o')
                    update_sum(i, j, k);

    llong mn = LLONG_MAX;
    vector<tuple<int, int, int>> ans;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < W; j++)
            for (int k = 0; k < H; k++) {
                if (sum[i][k][j] == mn) ans.emplace_back(i, j, k);
                else if (sum[i][k][j] < mn) {
                    ans.clear();
                    mn = sum[i][k][j];
                    ans.emplace_back(i, j, k);
                }
            }

    for (int i = 0; i < (int) ans.size(); i++) {
        if (i) cout << " ";
        auto [f, x, y] = ans[i];
        cout << "(" << f << ", " << x << ", " << y << ")";
    }

    cout << "\n";
}