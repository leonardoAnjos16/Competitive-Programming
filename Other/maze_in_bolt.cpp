#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int R, C;
vector<string> grid, rots;
vector<vector<bool>> vis;

bool collide(int row, int rot) {
    string &s = grid[row], &t = rots[rot];
    for (int i = 0; i < C; i++)
        if (s[i] == '1' && t[i] == '1')
            return true;

    return false;
}

bool possible(int row = 0, int rot = 0) {
    if (row < 0 || collide(row, rot)) return false;
    if (row >= R) return true;

    if (vis[row][rot]) return false;
    vis[row][rot] = true;

    return possible(row - 1, rot) || possible(row + 1, rot) || possible(row, (rot - 1 + C) % C) || possible(row, (rot + 1) % C);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    rots.resize(C);
    cin >> rots[0];

    for (int i = 1; i < C; i++)
        rots[i] = rots[i - 1].substr(1) + rots[i - 1][0];

    grid.resize(R + 1, string(C, '0'));
    for (int i = 1; i <= R; i++)
        cin >> grid[i];

    vis.assign(R + 1, vector<bool>(C, false));

    bool ans = possible();

    reverse(rots[0].begin(), rots[0].end());
    for (int i = 1; i < C; i++)
        rots[i] = rots[i - 1].substr(1) + rots[i - 1][0];

    vis.assign(R + 1, vector<bool>(C, false));

    ans |= possible();
    cout << (ans ? "Y" : "N") << "\n";
}