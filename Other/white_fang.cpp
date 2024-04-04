#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    bool possible = true;
    for (int i = 0; i < R && possible; i++)
        for (int j = 0; j < C && possible; j++)
            if (grid[i][j] == 'W')
                for (int di = -1; di <= 1 && possible; di++)
                    for (int dj = -1; dj <= 1 && possible; dj++)
                        if ((di || dj) && !(di && dj)) {
                            int ni = i + di, nj = j + dj;
                            if (ni >= 0 && ni < R && nj >= 0 && nj < C && grid[ni][nj] == 'P')
                                possible = false;
                        }

    cout << (possible ? "Yes" : "No") << "\n";
}