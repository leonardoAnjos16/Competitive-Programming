#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

int N, B;
vector<pair<int, int>> stations;
vector<vector<pair<int, int>>> g;
vector<vector<int>> dists;

int dist(pair<int, int> a, pair<int, int> b) {
    int dx = a.first - b.first, dy = a.second - b.second;
    return ceil(sqrt(dx * dx + dy * dy));
}

void get_dists() {
    dists.assign(N + 2, vector<int>(B + 1, INF));
    dists[0][0] = 0;

    using t3 = tuple<int, int, int>;
    priority_queue<t3, vector<t3>, greater<t3>> heap;
    heap.emplace(0, 0, 0);

    while (!heap.empty()) {
        auto [d, v, traveled] = heap.top(); heap.pop();
        if (d > dists[v][traveled]) continue;

        for (auto [u, c]: g[v]) {
            int curr = dist(stations[v], stations[u]);
            if (traveled + curr <= B && dists[v][traveled] + c * curr < dists[u][traveled + curr]) {
                dists[u][traveled + curr] = dists[v][traveled] + c * curr;
                heap.emplace(dists[u][traveled + curr], u, traveled + curr);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int xs, ys;
    cin >> xs >> ys;

    int xd, yd;
    cin >> xd >> yd;

    cin >> B;

    int C0; cin >> C0;
    int T; cin >> T;

    vector<int> C(T + 1, C0);
    for (int i = 1; i <= T; i++)
        cin >> C[i];

    cin >> N;

    stations.resize(N + 2);
    stations[0] = make_pair(xs, ys);
    stations[N + 1] = make_pair(xd, yd);

    g.assign(N + 2, vector<pair<int, int>>());
    for (int i = 1; i <= N; i++) {
        int x, y, l;
        cin >> x >> y >> l;

        stations[i] = make_pair(x, y);
        while (l--) {
            int j, m;
            cin >> j >> m;

            g[i].emplace_back(j + 1, C[m]);
            g[j + 1].emplace_back(i, C[m]);
        }
    }

    g[0].emplace_back(N + 1, C[0]);
    g[N + 1].emplace_back(0, C[0]);

    for (int i = 1; i <= N; i++) {
        g[0].emplace_back(i, C[0]);
        g[i].emplace_back(0, C[0]);

        g[i].emplace_back(N + 1, C[0]);
        g[N + 1].emplace_back(i, C[0]);
    }

    get_dists();

    int ans = INF;
    for (int i = 0; i <= B; i++)
        ans = min(ans, dists[N + 1][i]);

    if (ans >= INF) cout << "-1\n";
    else cout << ans << "\n";
}