#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Z; cin >> Z;
    while (Z--) {
        int N, W, L;
        cin >> N >> W >> L;

        vector<vector<int>> grid(N + 1, vector<int>(N + 1, 0));
        while (W--) {
            int row, col;
            cin >> row >> col;
            grid[row][col] = 1;
        }

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];

        int l = 1, r = N, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            bool possible = false;
            for (int i = mid; i <= N && !possible; i++)
                for (int j = mid; j <= N && !possible; j++) {
                    int cnt = grid[i][j] - grid[i - mid][j] - grid[i][j - mid] + grid[i - mid][j - mid];
                    if (cnt <= L) possible = true;
                }

            if (!possible) r = mid - 1;
            else l = mid + 1, ans = mid;
        }

        ans *= ans;
        cout << ans << "\n";
    }
}