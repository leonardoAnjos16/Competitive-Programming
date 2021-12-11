#include <bits/stdc++.h>

using namespace std;

#define long long long int

int R, C;
vector<string> maze;
vector<vector<int>> vis;
vector<vector<bool>> good;

bool get_good(int i, int j) {
    if (i < 0 || i >= R || j < 0 || j >= C || vis[i][j] == 1) return false;
    if (maze[i][j] == 'O') return good[i][j] = true;
    if (vis[i][j] == 2) return good[i][j];

    vis[i][j] = 1;
    int ni = i, nj = j;

    switch (maze[i][j]) {
        case '>':
            nj++;
            break;
        case 'v':
            ni++;
            break;
        case '<':
            nj--;
            break;
        default:
            ni--;
    }

    good[i][j] = get_good(ni, nj);
    vis[i][j] = 2;

    return good[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    maze.resize(R);
    for (int i = 0; i < R; i++)
        cin >> maze[i];

    vis.assign(R, vector<int>(C, 0));
    good.assign(R, vector<bool>(C, false));

    int ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (!vis[i][j]) get_good(i, j);
            ans += good[i][j];
        }

    cout << ans << "\n";
}