#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int SIZE = 4;

int sudoku[2 * SIZE][2 * SIZE];
bool rows[2 * SIZE][2 * SIZE];
bool cols[2 * SIZE][2 * SIZE];
int squares[SIZE][2 * SIZE];

int to_square(int i, int j) {
    return (i / SIZE) * (SIZE / 2) + (j / SIZE);
}

bool solve(int i = 0, int j = 0) {
    if (i >= 2 * SIZE) return true;
    if (j >= 2 * SIZE) return solve(i + 1);
    if (sudoku[i][j]) return solve(i, j + 1);

    for (int k = 0; k < 2 * SIZE; k++)
        if (!rows[i][k] && !cols[j][k] && squares[to_square(i, j)][k] < 2) {
            rows[i][k] = cols[j][k] = true;
            squares[to_square(i, j)][k]++;
            sudoku[i][j] = k + 1;

            if (solve(i, j + 1)) return true;

            rows[i][k] = cols[j][k] = false;
            squares[to_square(i, j)][k]--;
            sudoku[i][j] = 0;
        }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(rows, 0, sizeof rows);
        memset(cols, 0, sizeof cols);
        memset(squares, 0, sizeof squares);

        bool possible = true;
        for (int i = 0; i < 2 * SIZE; i++)
            for (int j = 0; j < 2 * SIZE; j++) {
                cin >> sudoku[i][j];
                if (!possible) continue;

                if (sudoku[i][j]) {
                    int k = sudoku[i][j] - 1;
                    if (rows[i][k] || cols[j][k] || squares[to_square(i, j)][k] >= 2) possible = false;
                    else {
                        rows[i][k] = cols[j][k] = true;
                        squares[to_square(i, j)][k]++;
                    }
                }
            }

        possible &= solve();
        cout << "Test case #" << t << ": ";

        cout << (possible ? "YES" : "NO") << "\n";
        if (possible) {
            for (int i = 0; i < 2 * SIZE; i++) {
                for (int j = 0; j < 2 * SIZE; j++) {
                    if (j) cout << " ";
                    cout << sudoku[i][j];
                }

                cout << "\n";
            }
        }
    }
}