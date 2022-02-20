#include <bits/stdc++.h>

using namespace std;

#define long long long int

int count_black(vector<string> &grid, int h, int w, int i, int j) {
    int cnt = 0;
    for (int dv = -1; dv <= 1; dv++)
        for (int dh = -1; dh <= 1; dh++) {
            int ni = i + dv, nj = j + dh;
            if (ni >= 0 && ni < h && nj >= 0 && nj < w && grid[ni][nj] == 'X')
                cnt++;
        }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> clues(h + 2, vector<int>(w + 2));
    for (int i = 0; i < h + 2; i++)
        for (int j = 0; j < w + 2; j++)
            cin >> clues[i][j];

    bool possible = true;
    vector<string> ans(h, string(w, '-'));

    for (int i = 0; i < h && possible; i++)
        for (int j = 0; j < w && possible; j++) {
            int cnt = count_black(ans, h, w, i - 1, j - 1);
            int diff = clues[i][j] - cnt;

            if (!diff) ans[i][j] = '.';
            else if (diff == 1) ans[i][j] = 'X';
            else possible = false;
        }

    for (int i = h + 1; i < h + 2 && possible; i++)
        for (int j = 0; j < w + 2 && possible; j++) {
            int cnt = count_black(ans, h, w, i - 1, j - 1);
            if (cnt != clues[i][j]) possible = false;
        }

    for (int i = 0; i < h + 2 && possible; i++)
        for (int j = w + 1; j < w + 2 && possible; j++) {
            int cnt = count_black(ans, h, w, i - 1, j - 1);
            if (cnt != clues[i][j]) possible = false;
        }

    if (!possible) cout << "impossible\n";
    else {
        for (int i = 0; i < h; i++)
            cout << ans[i] << "\n";
    }
}