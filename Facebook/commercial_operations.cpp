#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const ldouble INF = 1e18 + 5;

int N;
vector<vector<tuple<int, int, int>>> g;
vector<ldouble> dists;

void get_dists(ldouble t) {
    vector<bool> vis(N, false);
    dists.assign(N, INF);
    dists[0] = 0.0L;

    priority_queue<pair<ldouble, int>, vector<pair<ldouble, int>>, greater<pair<ldouble, int>>> heap;
    heap.emplace(0.0L, 0);

    while (!heap.empty()) {
        int v = heap.top().second; heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, A, B]: g[v])
            if (!vis[u] && dists[v] + A * t + B < dists[u]) {
                dists[u] = dists[v] + A * t + B;
                heap.emplace(dists[u], u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(5) << fixed;

    int M;
    cin >> N >> M;

    g.assign(N, vector<tuple<int, int, int>>());
    while (M--) {
        int I, J, A, B;
        cin >> I >> J >> A >> B;

        g[I - 1].emplace_back(J - 1, A, B);
        g[J - 1].emplace_back(I - 1, A, B);
    }

    ldouble l = 0.0L, r = 24.0L * 60.0L;
    for (int i = 0; i < 100; i++) {
        ldouble t1 = l + (r - l) / 3.0L;
        ldouble t2 = r - (r - l) / 3.0L;

        get_dists(t1);
        ldouble c1 = dists[N - 1];

        get_dists(t2);
        ldouble c2 = dists[N - 1];

        if (c1 < c2) l = t1;
        else r = t2;
    }

    get_dists(l);

    ldouble ans = dists[N - 1];
    cout << ans << "\n";
}