#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N, M;
vector<string> grid;

void rotate_left(char &dir) {
    if (dir == 'N') dir = 'O';
    else if (dir == 'L') dir = 'N';
    else if (dir == 'S') dir = 'L';
    else if (dir == 'O') dir = 'S';
}

void rotate_right(char &dir) {
    if (dir == 'N') dir = 'L';
    else if (dir == 'L') dir = 'S';
    else if (dir == 'S') dir = 'O';
    else if (dir == 'O') dir = 'N';
}

void move_forward(int &r, int &c, char dir) {
    if (dir == 'N' && r >= 1 && grid[r - 1][c] != '#') r--;
    else if (dir == 'L' && c + 1 < M && grid[r][c + 1] != '#') c++;
    else if (dir == 'S' && r + 1 < N && grid[r + 1][c] != '#') r++;
    else if (dir == 'O' && c >= 1 && grid[r][c - 1] != '#') c--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S;
    while (cin >> N >> M >> S, N || M || S) {
        int r, c; char dir;
        grid.resize(N);

        for (int i = 0; i < N; i++) {
            cin >> grid[i];
            for (int j = 0; j < M; j++)
                if (grid[i][j] >= 'A' && grid[i][j] <= 'Z')
                    r = i, c = j, dir = grid[i][j];
        }

        string instructions; cin >> instructions;

        int ans = 0;
        for (char i: instructions) {
            if (i == 'D') rotate_right(dir);
            else if (i == 'E') rotate_left(dir);
            else {
                move_forward(r, c, dir);
                if (grid[r][c] == '*') {
                    ans++;
                    grid[r][c] = '.';
                }
            }
        }

        cout << ans << "\n";
    }
}