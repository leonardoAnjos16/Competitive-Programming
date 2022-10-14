#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 9;

char grid[MAX][MAX];
bool zigs[MAX][MAX], zags[MAX][MAX], squares[MAX][MAX];

int get_zig(int row, int col) {
    int ans = col - row;
    if (ans < 0) ans += MAX;
    return ans;
}

int get_zag(int row, int col) {
    int ans = row + col;
    if (ans >= MAX) ans -= MAX;
    return ans;
}

int get_square(int row, int col) {
    return 3 * (row / 3) + (col / 3);
}

int solve(int row = 0, int col = 0) {
    if (row >= MAX) return grid[0][0] - '0';
    if (col >= MAX) return solve(row + 1);
    if (grid[row][col] != '.') return solve(row, col + 1);

    int zig = get_zig(row, col);
    int zag = get_zag(row, col);
    int square = get_square(row, col);

    for (int i = 0; i < MAX; i++)
        if (!zigs[zig][i] && !zags[zag][i] && !squares[square][i]) {
            grid[row][col] = '0' + i;
            zigs[zig][i] = zags[zag][i] = squares[square][i] = true;

            int ans = solve(row, col + 1);
            if (ans != -1) return ans;

            grid[row][col] = '.';
            zigs[zig][i] = zags[zag][i] = squares[square][i] = false;
        }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int ans = 0;
    while (N--) {
        memset(zigs, 0, sizeof zigs);
        memset(zags, 0, sizeof zags);
        memset(squares, 0, sizeof squares);

        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++) {
                cin >> grid[i][j];
                if (grid[i][j] != '.') {
                    int v = grid[i][j] - '0';
                    int zig = get_zig(i, j);
                    int zag = get_zag(i, j);
                    int square = get_square(i, j);
                    zigs[zig][v] = zags[zag][v] = squares[square][v] = true;
                }
            }

        ans += solve();
    }

    cout << ans << "\n";
}