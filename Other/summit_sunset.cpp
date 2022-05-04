#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18 + 5;

int N;
vector<vector<int>> h;
vector<vector<long>> dist;

void get_dist() {
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    dist.assign(N, vector<long>(N, INF));
    dist[0][0] = 0LL;

    priority_queue<tuple<long, int, int>, vector<tuple<long, int, int>>, greater<tuple<long, int, int>>> heap;
    heap.emplace(0LL, 0, 0);

    while (!heap.empty()) {
        auto [d, row, col] = heap.top(); heap.pop();
        if (vis[row][col]) continue;
        vis[row][col] = true;

        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if ((i || j) && !(i && j)) {
                    int nrow = row + i, ncol = col + j;
                    if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < N && !vis[nrow][ncol]) {
                        int diff = abs(h[row][col] - h[nrow][ncol]);
                        int weight = diff * diff;

                        if (dist[row][col] + weight < dist[nrow][ncol]) {
                            dist[nrow][ncol] = dist[row][col] + weight;
                            heap.emplace(dist[nrow][ncol], nrow, ncol);
                        }
                    }
                }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int mx = 0;
    h.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> h[i][j];
            mx = max(mx, h[i][j]);
        }

    get_dist();

    long ans = INF;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (h[i][j] == mx)
                ans = min(ans, dist[i][j]);

    cout << ans << "\n";
}