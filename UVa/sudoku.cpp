#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> rows, cols, boxes;
vector<vector<int>> grid;

int get_box(int row, int col) {
    return (row / n) * n + col / n;
}

bool solve(int row = 0, int col = 0) {
    if (row >= n * n) return true;
    if (col >= n * n) return solve(row + 1);

    if (grid[row][col]) return solve(row, col + 1);

    int box = get_box(row, col);
    int used = rows[row] | cols[col] | boxes[box];

    for (int i = 0; i < n * n; i++)
        if (!(used & (1 << i))) {
            rows[row] |= 1 << i;
            cols[col] |= 1 << i;
            boxes[box] |= 1 << i;
            grid[row][col] = i + 1;

            if (solve(row, col + 1)) return true;

            rows[row] ^= 1 << i;
            cols[col] ^= 1 << i;
            boxes[box] ^= 1 << i;
            grid[row][col] = 0;
        }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool first = true;
    while (cin >> n) {
        if (!first) cout << "\n";
        first = false;

        rows.assign(n * n, 0);
        cols.assign(n * n, 0);
        boxes.assign(n * n, 0);
        grid.assign(n * n, vector<int>(n * n));

        bool possible = true;
        for (int i = 0; i < n * n; i++)
            for (int j = 0; j < n * n; j++) {
                cin >> grid[i][j];

                if (grid[i][j]) {
                    int box = get_box(i, j);
                    int idx = grid[i][j] - 1;

                    if (rows[i] & (1 << idx)) possible = false;
                    else if (cols[j] & (1 << idx)) possible = false;
                    else if (boxes[box] & (1 << idx)) possible = false;
                    else {
                        rows[i] |= 1 << idx;
                        cols[j] |= 1 << idx;
                        boxes[box] |= 1 << idx;
                    }
                }
            }

        possible &= solve();
        if (!possible) cout << "NO SOLUTION\n";
        else {
            for (int i = 0; i < n * n; i++) {
                for (int j = 0; j < n * n; j++) {
                    if (j) cout << " ";
                    cout << grid[i][j];
                }

                cout << "\n";
            }
        }
    }
}