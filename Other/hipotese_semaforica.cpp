#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int N;
vector<int> V, S;
vector<vector<pair<int, int>>> g;
vector<int> dists;

void get_dists(int start) {
    vector<bool> vis(N, false);

    dists.assign(N, INF);
    dists[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        auto [d, v] = heap.top(); heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        int t = d % V[S[v] - 1];
        int wait = (V[S[v] - 1] - t) % V[S[v] - 1];

        for (auto [u, w]: g[v])
            if (!vis[u] && d + wait + w < dists[u]) {
                dists[u] = d + wait + w;
                heap.emplace(dists[u], u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, K;
    cin >> N >> M >> K;

    V.resize(K);
    for (int i = 0; i < K; i++)
        cin >> V[i];

    g.assign(N, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int U, W, C;
        cin >> U >> W >> C;

        g[U - 1].emplace_back(W - 1, C);
        g[W - 1].emplace_back(U - 1, C);
    }

    S.resize(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];

    int B, E;
    cin >> B >> E;

    get_dists(B - 1);

    int D = dists[E - 1];
    cout << D << "\n";
}