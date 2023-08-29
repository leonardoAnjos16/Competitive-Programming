#include <bits/stdc++.h>

using namespace std;

const int BOTTOM = 0;
const int FRONT = 1;
const int RIGHT = 2;
const int TOP = 3;
const int BACK = 4;
const int LEFT = 5;

struct Cube {
    array<int, 6> colors;
    int bottom, front, right;

    Cube(array<int, 6> &colors, int bottom, int front, int right):
        colors(colors), bottom(bottom), front(front), right(right) {}

    bool operator <(Cube const &other) const {
        return make_tuple(colors, bottom, front, right) < make_tuple(other.colors, other.bottom, other.front, other.right);
    }
};

int n;
vector<vector<int>> c;
map<tuple<Cube, int, int>, bool> memo;

int opposite(int face) {
    if (face == BOTTOM) return TOP;
    if (face == FRONT) return BACK;
    if (face == RIGHT) return LEFT;
    if (face == TOP) return BOTTOM;
    if (face == BACK) return FRONT;
    return RIGHT;
}

bool possible(array<int, 6> &colors, int bottom = BOTTOM, int front = FRONT, int right = RIGHT, int row = 0, int col = 0) {
    if (colors[bottom] != -1 && colors[bottom] != c[row][col]) return false;

    Cube cube(colors, bottom, front, right);
    tuple<Cube, int, int> state(cube, row, col);

    if (memo.count(state)) return memo[state];

    int pcolor = colors[bottom];
    colors[bottom] = c[row][col];

    if (row + 1 >= n && col + 1 >= n) return memo[state] = true;
    if (row + 1 < n && possible(colors, front, opposite(bottom), right, row + 1, col)) return memo[state] = true;
    if (col + 1 < n && possible(colors, right, front, opposite(bottom), row, col + 1)) return memo[state] = true;

    colors[bottom] = pcolor;
    return memo[state] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;

        c.assign(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> c[i][j];

        array<int, 6> colors = { -1, -1, -1, -1, -1, -1 };
        memo.clear();

        if (!possible(colors)) cout << "No\n";
        else {
            cout << "Yes\n";
            for (int i = 0; i < 6; i++)
                if (colors[i] == -1)
                    colors[i] = 0;

            cout << colors[BOTTOM] << " " << colors[LEFT] << " " << colors[BACK] << " " << colors[FRONT] << " " << colors[RIGHT] << " " << colors[TOP] << "\n";
        }
    }
}