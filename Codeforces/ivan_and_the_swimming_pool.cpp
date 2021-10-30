#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N, M;
vector<vector<int>> area;
vector<vector<bool>> vis;

int size(int i, int j, int depth) {
    if (i < 0 || i >= N) return 0;
    if (j < 0 || j >= M) return 0;

    if (vis[i][j]) return 0;
    if (area[i][j] < depth) return 0;

    int ans = 1;
    vis[i][j] = true;

    ans += size(i - 1, j, depth);
    ans += size(i, j + 1, depth);
    ans += size(i + 1, j, depth);
    ans += size(i, j - 1, depth);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S;
    cin >> S >> N >> M;

    int mx = 0;
    area.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> area[i][j];
            mx = max(mx, area[i][j]);
        }

    int l = 0, r = mx, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        int mx_size = 0;
        vis.assign(N, vector<bool>(M, false));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                mx_size = max(mx_size, size(i, j, mid));

        if (mx_size < S) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    cout << ans << "\n";
}