#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, R, Q, t = 1;
    while (cin >> C >> R >> Q, C || R || Q) {
        if (t > 1) cout << "\n";

        vector<llong> f(C);
        for (int i = 0; i < C; i++)
            cin >> f[i];

        vector<vector<llong>> dists(C, vector<llong>(C, INF));
        for (int i = 0; i < R; i++) {
            int c1, c2; llong d;
            cin >> c1 >> c2 >> d;
            dists[c1 - 1][c2 - 1] = dists[c2 - 1][c1 - 1] = min(dists[c1 - 1][c2 - 1], d);
        }

        vector<vector<vector<llong>>> best(C, vector<vector<llong>>(C, vector<llong>(C)));
        for (int costliest = 0; costliest < C; costliest++) {
            for (int i = 0; i < C; i++)
                for (int j = 0; j < C; j++)
                    best[costliest][i][j] = f[i] <= f[costliest] && f[j] <= f[costliest] ? dists[i][j] : INF;

            for (int k = 0; k < C; k++)
                for (int i = 0; i < C; i++)
                    for (int j = 0; j < C; j++)
                        best[costliest][i][j] = min(best[costliest][i][j], best[costliest][i][k] + best[costliest][k][j]);
        }

        cout << "Case #" << t++ << "\n";
        while (Q--) {
            int c1, c2;
            cin >> c1 >> c2;

            llong ans = INF;
            for (int i = 0; i < C; i++)
                ans = min(ans, best[i][c1 - 1][c2 - 1] + f[i]);

            if (ans >= INF) cout << "-1\n";
            else cout << ans << "\n";
        }
    }
}