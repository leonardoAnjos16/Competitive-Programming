#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

vector<int> route;
vector<vector<int>> edge, dist;
vector<vector<int>> memo;

int roads(int l, int r) {
    int sum = 0;
    for (int i = l; i < r; i++)
        sum += edge[route[i]][route[i + 1]];

    if (dist[route[l]][route[r]] == sum) return 0;

    int &ans = memo[l][r];
    if (~ans) return ans;

    ans = INF;
    for (int m = l; m < r; m++)
        ans = min(ans, roads(l, m) + roads(m + 1, r) + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t = 1;
    while (cin >> n, n) {
        edge.assign(n, vector<int>(n));
        dist.assign(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> edge[i][j];

                dist[i][j] = edge[i][j];
                if (i != j && !dist[i][j])
                    dist[i][j] = INF;
            }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int m; cin >> m;

        route.resize(m);
        for (int i = 0; i < m; i++)
            cin >> route[i];

        memo.assign(m + 5, vector<int>(m + 5, -1));

        int ans = roads(0, m - 1);
        cout << "Case " << t++ << ": " << ans << "\n";
    }
}