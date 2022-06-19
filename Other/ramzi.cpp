#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 5;

int N;
vector<vector<pair<int, int>>> walk, car;
vector<pair<int, int>> dists;

pair<int, int> operator +(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

void get_dists(int start) {
    vector<bool> vis(N, false);
    dists.assign(N, make_pair(INF, INF));
    dists[start] = make_pair(0, 0);

    using t3 = tuple<int, int, int>;
    priority_queue<t3, vector<t3>, greater<t3>> heap;
    heap.emplace(0, 0, start);

    while (!heap.empty()) {
        int v = get<2>(heap.top()); heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, w]: walk[v])
            if (!vis[u] && dists[v] + make_pair(w, 0) < dists[u]) {
                dists[u] = dists[v] + make_pair(w, 0);
                heap.emplace(dists[u].first, dists[u].second, u);
            }

        for (auto [u, w]: car[v])
            if (!vis[u] && dists[v] + make_pair(0, w) < dists[u]) {
                dists[u] = dists[v] + make_pair(0, w);
                heap.emplace(dists[u].first, dists[u].second, u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int M;
        cin >> N >> M;

        walk.assign(N, vector<pair<int, int>>());
        car.assign(N, vector<pair<int, int>>());

        for (int i = 0; i < M; i++) {
            int a, b, c, k;
            cin >> a >> b >> c >> k;

            if (k == 1) {
                walk[a - 1].emplace_back(b - 1, c);
                walk[b - 1].emplace_back(a - 1, c);
            } else {
                car[a - 1].emplace_back(b - 1, c);
                car[b - 1].emplace_back(a - 1, c);
            }
        }

        int x, y;
        cin >> x >> y;

        get_dists(x - 1);

        pair<int, int> ans = dists[y - 1];
        if (ans.first >= INF || ans.second >= INF) cout << "-1\n";
        else cout << ans.first << " " << (ans.first + ans.second) << "\n";
    }
}