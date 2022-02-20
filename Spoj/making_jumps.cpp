#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 15;

int n;
vector<pair<int, int>> board;
bool vis[MAX][MAX];

int not_reachable(int remaining, int i = 0, int j = 0) {
    assert(remaining >= 0);

    int ans = remaining;
    for (int di = -2; di <= 2; di++)
        for (int dj = -2; dj <= 2; dj++)
            if (di && dj && abs(di) != abs(dj)) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= n) continue;
                if (nj < board[ni].first || nj >= board[ni].first + board[ni].second) continue;
                if (vis[ni][nj]) continue;

                vis[ni][nj] = true;
                ans = min(ans, not_reachable(remaining - 1, ni, nj));
                vis[ni][nj] = false;
            }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_case = 1;
    while (cin >> n, n) {
        cout << "Case " << num_case++ << ", ";

        board.resize(n);
        int remaining = 0;

        for (int i = 0; i < n; i++) {
            int offset, size;
            cin >> offset >> size;

            board[i] = make_pair(offset, size);
            remaining += size;
        }

        memset(vis, 0, sizeof vis);
        vis[0][0] = true;

        int ans = not_reachable(remaining - 1);
        cout << ans << " square" << (ans == 1 ? " " : "s ") << "can not be reached.\n";
    }
}