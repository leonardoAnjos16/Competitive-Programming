#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e6 + 5;
const int MAX = 26;

int g[MAX][MAX], dists[MAX][MAX];

void get_dists() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) {
            if (i == j) dists[i][j] = 0;
            else if (g[i][j]) dists[i][j] = 1;
            else dists[i][j] = INF;
        }

    for (int k = 0; k < MAX; k++)
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string S; cin >> S;
        memset(g, 0, sizeof g);

        int K; cin >> K;
        while (K--) {
            string uv; cin >> uv;
            int u = uv[0] - 'A';
            int v = uv[1] - 'A';
            g[u][v] = 1;
        }

        get_dists();

        int ans = INF;
        for (int i = 0; i < MAX; i++) {
            int cost = 0;
            bool possible = true;

            for (int j = 0, n = S.size(); j < n && possible; j++) {
                if (dists[S[j] - 'A'][i] == INF) possible = false;
                else cost += dists[S[j] - 'A'][i];
            }

            if (possible) ans = min(ans, cost);
        }

        cout << "Case #" << t << ": ";
        if (ans == INF) cout << "-1\n";
        else cout << ans << "\n";
    }
}