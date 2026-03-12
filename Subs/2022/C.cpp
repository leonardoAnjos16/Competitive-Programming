#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e3;
const int INF = 1e9 + 5;
const int dr[4] = { 1, 0, -1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

bool vis[MAX + 1][MAX + 1];
bool blocked[MAX + 1][MAX + 1][4];

int size(int row, int col) {
    if (row < 0 || row > MAX || col < 0 || col > MAX) return -INF;
    if (vis[row][col]) return 0;

    int ans = 1;
    vis[row][col] = true;

    for (int i = 0; i < 4; i++)
        if (!blocked[row][col][i])
            ans += size(row + dr[i], col + dc[i]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> X(N + 1), Y(N + 1);
    for (int i = 0; i <= N; i++)
        cin >> X[i] >> Y[i];

    memset(blocked, 0, sizeof blocked);
    for (int i = 1; i <= N; i++) {
        if (X[i] == X[i - 1]) {
            for (int j = min(Y[i], Y[i - 1]); j < max(Y[i], Y[i - 1]); j++)
                blocked[j][X[i] - 1][1] = blocked[j][X[i]][3] = true;
        } else {
            assert(Y[i] == Y[i - 1]);
            for (int j = min(X[i], X[i - 1]); j < max(X[i], X[i - 1]); j++)
                blocked[Y[i] - 1][j][0] = blocked[Y[i]][j][2] = true;
        }
    }

    int ans = 0;
    memset(vis, 0, sizeof vis);

    for (int i = 0; i <= MAX; i++)
        for (int j = 0; j <= MAX; j++)
            ans = max(ans, size(i, j));

    cout << ans << "\n";
}