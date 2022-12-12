#include <bits/stdc++.h>

using namespace std;

int m;
string wall[2];

bool possible(int row, int col = 0, int vis = 1) {
    if (col + 1 >= m) return true;

    if (vis < 2 && wall[1 - row][col] == 'B')
        return possible(1 - row, col, vis + 1);

    if (wall[row][col + 1] == 'W') return false;
    return possible(row, col + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> m;
        for (int i = 0; i < 2; i++)
            cin >> wall[i];

        bool ans = false;
        if (wall[0][0] == 'B') ans |= possible(0);
        if (wall[1][0] == 'B') ans |= possible(1);

        cout << (ans ? "YES" : "NO") << "\n";
    }
}