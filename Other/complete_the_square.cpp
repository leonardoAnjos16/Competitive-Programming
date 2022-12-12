#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<string> grid;

bool seg(int row, int col) {
    return row >= 0 && row < 2 * R - 1 && col >= 0 && col < 2 * C - 1 && grid[row][col] != '.';
}

int squares(int row, int col) {
    if (row & 1) {
        int left = seg(row, col - 2) + seg(row - 1, col - 1) + seg(row + 1, col - 1);
        int right = seg(row, col + 2) + seg(row - 1, col + 1) + seg(row + 1, col + 1);

        int ans = (left == 3) + (right == 3);
        if (ans) grid[row][col] = '|';

        if (left == 2 && right == 3) {
            if (!seg(row, col - 2)) ans += squares(row, col - 2);
            else if (!seg(row - 1, col - 1)) ans += squares(row - 1, col - 1);
            else ans += squares(row + 1, col - 1);
        }

        if (left == 3 && right == 2) {
            if (!seg(row, col + 2)) ans += squares(row, col + 2);
            else if (!seg(row - 1, col + 1)) ans += squares(row - 1, col + 1);
            else ans += squares(row + 1, col + 1);
        }

        return ans;
    }

    int top = seg(row - 2, col) + seg(row - 1, col - 1) + seg(row - 1, col + 1);
    int bottom = seg(row + 2, col) + seg(row + 1, col - 1) + seg(row + 1, col + 1);

    int ans = (top == 3) + (bottom == 3);
    if (ans) grid[row][col] = '-';

    if (top == 2 && bottom == 3) {
        if (!seg(row - 2, col)) ans += squares(row - 2, col);
        else if (!seg(row - 1, col - 1)) ans += squares(row - 1, col - 1);
        else ans += squares(row - 1, col + 1);
    }

    if (top == 3 && bottom == 2) {
        if (!seg(row + 2, col)) ans += squares(row + 2, col);
        else if (!seg(row + 1, col - 1)) ans += squares(row + 1, col - 1);
        else ans += squares(row + 1, col + 1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    grid.resize(2 * R - 1);
    for (int i = 0; i < 2 * R - 1; i++)
        cin >> grid[i];

    int ans = 0;
    for (int i = 0; i < 2 * R - 1; i++) {
        if (i & 1) {
            for (int j = 0; j < 2 * C - 1; j += 2)
                if (grid[i][j] == '.') ans += squares(i, j);
        } else {
            for (int j = 1; j < 2 * C - 1; j += 2)
                if (grid[i][j] == '.') ans += squares(i, j);
        }
    }

    cout << ans << "\n";
}