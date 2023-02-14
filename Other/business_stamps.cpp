#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;

int N, M;
vector<vector<int>> stamps;
vector<vector<bool>> vis;

bool reachable(int bought, int r, int c, int rw, int cw) {
    if (!(bought & (1 << stamps[r][c]))) return false;
    if (r == rw && c == cw) return true;

    vis[r][c] = true;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if ((dr || dc) && !(dr && dc)) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && !vis[nr][nc] && reachable(bought, nr, nc, rw, cw))
                    return true;
            }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int rh, ch;
    cin >> rh >> ch;

    int rw, cw;
    cin >> rw >> cw;

    stamps.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> stamps[i][j];
            stamps[i][j]--;
        }

    int ans = MAX;
    for (int i = 1; i < (1 << MAX); i++) {
        vis.assign(N, vector<bool>(M, false));
        if (reachable(i, rh - 1, ch - 1, rw - 1, cw - 1))
            ans = min(ans, __builtin_popcount(i));
    }

    cout << ans << "\n";
}