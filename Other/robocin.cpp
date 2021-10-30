#include <bits/stdc++.h>

using namespace std;

#define long long long int

const char directions[4] = { 'N', 'L', 'S', 'O' };

char right(char dir) {
    int idx = 0;
    while (directions[idx] != dir) idx++;
    return directions[(idx + 1) % 4];
}

char left(char dir) {
    int idx = 0;
    while (directions[idx] != dir) idx++;
    return directions[(idx + 3) % 4];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int col, row;
    cin >> col >> row;

    vector<vector<bool>> marked(col + 1, vector<bool>(row + 1, false));

    int robots; cin >> robots;
    while (robots--) {
        int x, y; char dir;
        cin >> x >> y >> dir;

        string instructions;
        cin >> instructions;

        bool lost = false;
        for (char c: instructions) {
            if (c == 'D') dir = right(dir);
            else if (c == 'E') dir = left(dir);
            else {
                int dx = 0, dy = 0;
                if (dir == 'N') dy = 1;
                else if (dir == 'L') dx = 1;
                else if (dir == 'S') dy = -1;
                else dx = -1;

                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx > col || ny < 0 || ny > row) {
                    if (marked[x][y]) nx = x, ny = y;
                    else {
                        marked[x][y] = true;
                        lost = true;
                        break;
                    }
                }

                x = nx; y = ny;
            }
        }

        cout << x << " " << y << " " << dir;
        cout << (lost ? " PERDIDO\n" : "\n");
    }
}