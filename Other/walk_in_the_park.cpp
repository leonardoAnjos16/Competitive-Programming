#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e8 + 5;

int N, M;
vector<string> park;

vector<vector<int>> get_dists(int i, int j) {
    vector<vector<int>> dists(N, vector<int>(M, INF));
    dists[i][j] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    heap.emplace(0, i, j);

    vector<vector<bool>> vis(N, vector<bool>(M, false));
    while (!heap.empty()) {
        auto [dist, ni, nj] = heap.top(); heap.pop();
        if (vis[ni][nj]) continue;
        vis[ni][nj] = true;

        for (int di = -1; di <= 1; di++)
            for (int dj = -1; dj <= 1; dj++)
                if ((di || dj) && !(di && dj)) {
                    int nni = ni + di, nnj = nj + dj;
                    if (nni < 0 || nni >= N || nnj < 0 || nnj >= M || park[nni][nnj] == '#') continue;

                    if (!vis[nni][nnj] && dists[ni][nj] + 1 < dists[nni][nnj]) {
                        dists[nni][nnj] = dists[ni][nj] + 1;
                        heap.emplace(dists[nni][nnj], nni, nnj);
                    }
                }
    }

    return dists;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    park.resize(N);
    for (int i = 0; i < N; i++)
        cin >> park[i];

    int far, fac, sar, sac;
    cin >> far >> fac >> sar >> sac;

    int fbr, fbc, sbr, sbc;
    cin >> fbr >> fbc >> sbr >> sbc;

    vector<vector<int>> from_fa = get_dists(far, fac);
    vector<vector<int>> from_sa = get_dists(sar, sac);

    vector<vector<int>> from_fb = get_dists(fbr, fbc);
    vector<vector<int>> from_sb = get_dists(sbr, sbc);

    int ans = INF;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans = min(ans, from_fa[i][j] + from_sa[i][j] + from_fb[i][j] + from_sb[i][j]);

    if (ans >= INF) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
}