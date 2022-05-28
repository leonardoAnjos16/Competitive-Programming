#include <bits/stdc++.h>

using namespace std;

#define long long long int

int M, N;
vector<string> grid;
vector<vector<vector<bool>>> vis;

void solve(int r, int c, int dir) {
    if (r < 0 || r >= M || c < 0 || c >= N || grid[r][c] == '#' || vis[r][c][dir]) return;

    vis[r][c][dir] = true;
    if (grid[r][c] == '.')
        grid[r][c] = '@';

    if (grid[r][c] == '@' || grid[r][c] == 'O') {
        if (dir == 0) solve(r - 1, c, dir);
        else if (dir == 1) solve(r, c + 1, dir);
        else if (dir == 2) solve(r + 1, c, dir);
        else solve(r, c - 1, dir);
    } else if (grid[r][c] == '/') {
        if (dir == 0) solve(r, c + 1, 1);
        else if (dir == 1) solve(r - 1, c, 0);
        else if (dir == 2) solve(r, c - 1, 3);
        else solve(r + 1, c, 2);
    } else {
        // '\'
        if (dir == 0) solve(r, c - 1, 3);
        else if (dir == 1) solve(r + 1, c, 2);
        else if (dir == 2) solve(r, c + 1, 1);
        else solve(r - 1, c, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    grid.resize(M);
    int r = -1, c = -1;

    for (int i = 0; i < M; i++) {
        cin >> grid[i];
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 'O')
                r = i, c = j;
    }

    vis.assign(M, vector<vector<bool>>(N, vector<bool>(4, false)));

    solve(r, c, 0);
    solve(r, c, 1);
    solve(r, c, 2);
    solve(r, c, 3);

    for (int i = 0; i < M; i++)
        cout << grid[i] << "\n";
}