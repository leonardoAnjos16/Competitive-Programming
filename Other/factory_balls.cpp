#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 5;

int N, K, M;
vector<int> c, r, blocked;
vector<vector<int>> dists;

int update_regions(int regions, int equips, int color) {
    int nregions = 0;
    for (int i = 0; i < N; i++) {
        if ((blocked[equips] & (1 << i)) && (regions & (1 << i)))
            nregions |= 1 << i;
        else if (!(blocked[equips] & (1 << i)) && c[i] == color)
            nregions |= 1 << i;
    }

    return nregions;
}

void get_dists(int regions, int equips) {
    vector<vector<bool>> vis(1 << N, vector<bool>(1 << M, false));
    dists.assign(1 << N, vector<int>(1 << M, INF));
    dists[regions][equips] = 0;

    using t3 = tuple<int, int, int>;
    priority_queue<t3, vector<t3>, greater<t3>> heap;
    heap.emplace(0, regions, equips);

    while (!heap.empty()) {
        auto [d, re, eq] = heap.top(); heap.pop();
        if (vis[re][eq]) continue;
        vis[re][eq] = true;

        for (int i = 0; i < M; i++)
            if (!vis[re][eq ^ (1 << i)] && dists[re][eq] + 1 < dists[re][eq ^ (1 << i)]) {
                dists[re][eq ^ (1 << i)] = dists[re][eq] + 1;
                heap.emplace(dists[re][eq ^ (1 << i)], re, eq ^ (1 << i));
            }

        for (int i = 0; i < K; i++) {
            int nre = update_regions(re, eq, i);
            if (!vis[nre][eq] && dists[re][eq] + 1 < dists[nre][eq]) {
                dists[nre][eq] = dists[re][eq] + 1;
                heap.emplace(dists[nre][eq], nre, eq);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> M;

    c.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        c[i]--;
    }

    r.assign(M, 0);
    for (int i = 0; i < M; i++) {
        int size; cin >> size;
        for (int j = 0; j < size; j++) {
            int rj; cin >> rj;
            r[i] |= 1 << (rj - 1);
        }
    }

    blocked.assign(1 << M, 0);
    for (int i = 0; i < (1 << M); i++)
        for (int j = 0; j < M; j++)
            if (i & (1 << j))
                blocked[i] |= r[j];

    int regions = 0;
    for (int i = 0; i < N; i++)
        if (!c[i]) regions |= 1 << i;

    get_dists(regions, 0);

    int ans = dists[(1 << N) - 1][0];
    if (ans >= INF) cout << "-1\n";
    else cout << ans << "\n";
}