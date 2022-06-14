#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++)
        cin >> grid[i];

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (grid[i][j] == '.')
                for (char color = '1'; color <= '5'; color++) {
                    if (i && grid[i - 1][j] == color) continue;
                    if (i + 1 < H && grid[i + 1][j] == color) continue;
                    if (j && grid[i][j - 1] == color) continue;
                    if (j + 1 < W && grid[i][j + 1] == color) continue;

                    grid[i][j] = color;
                    break;
                }

    for (int i = 0; i < H; i++)
        cout << grid[i] << "\n";
}