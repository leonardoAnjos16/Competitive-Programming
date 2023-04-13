#include <bits/stdc++.h>

using namespace std;

int n;
string grid[2];
vector<vector<bool>> vis;

void traverse(int row = 0, int col = 0) {
    if (row < 0 || row >= 2 || col < 0 || col >= n || grid[row][col] == '1' || vis[row][col]) return;

    vis[row][col] = true;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            traverse(row + dr, col + dc);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> grid[0] >> grid[1];

    vis.assign(2, vector<bool>(n, false));

    traverse();

    bool possible = vis[1][n - 1];
    cout << (possible ? "YES" : "NO") << "\n";
}