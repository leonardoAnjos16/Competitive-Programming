#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 55;

int n, m;
vector<string> maze;
vector<bitset<MAX>> vis;

void visit(int i, int j) {
    vis[i][j] = true;
    for (int k = -1; k <= 1; k++)
        for (int l = -1; l <= 1; l++)
            if ((k || l) && (!k || !l)) {
                int ni = i + k;
                int nj = j + l;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && maze[ni][nj] != '#')
                    visit(ni, nj);
            }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> m;

        maze.resize(n);
        for (int i = 0; i < n; i++)
            cin >> maze[i];

        int good = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'G') good++;
                else if (maze[i][j] == 'B') {
                    for (int k = -1; k <= 1; k++)
                        for (int l = -1; l <= 1; l++)
                            if ((k || l) && (!k || !l)) {
                                int ni = i + k;
                                int nj = j + l;

                                if (ni >= 0 && ni < n && nj >=0 && nj < m && maze[ni][nj] == '.')
                                    maze[ni][nj] = '#';
                            }
                }
            }

        vis.assign(n, bitset<MAX>());
        if (maze[n - 1][m - 1] != '#')
            visit(n - 1, m - 1);

        bool possible = maze[n - 1][m - 1] != '#' || !good;
        for (int i = 0; i < n && possible; i++)
            for (int j = 0; j < m && possible; j++) {
                if (maze[i][j] == 'B' && vis[i][j]) possible = false;
                if (maze[i][j] == 'G') {
                    good++;
                    if (!vis[i][j])
                        possible = false;
                }
            }

        cout << (possible ? "Yes" : "No") << "\n";
    }
}