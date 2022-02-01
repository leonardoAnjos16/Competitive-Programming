#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18;

vector<vector<pair<int, long>>> g;
vector<long> dists;

void get_dists(int u) {
    vector<bool> vis(g.size(), false);
    dists.assign(g.size(), INF);
    dists[u] = 0LL;

    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> heap;
    heap.emplace(0LL, u);

    while (!heap.empty()) {
        u = heap.top().second; heap.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w]: g[u])
            if (!vis[v] && dists[u] + w < dists[v]) {
                dists[v] = dists[u] + w;
                heap.emplace(dists[v], v);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; long L, R, C;
    cin >> N >> L >> R >> C;

    int u, v;
    cin >> u >> v;

    vector<int> A(N);
    vector<int> numbers;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        numbers.push_back(A[i]);
    }

    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    int num_vertices = N + (int) numbers.size();
    g.assign(num_vertices, vector<pair<int, long>>());

    for (int i = 0; i < N; i++) {
        if (i) g[i].emplace_back(i - 1, L);
        if (i + 1 < N) g[i].emplace_back(i + 1, R);

        int idx = N + lower_bound(numbers.begin(), numbers.end(), A[i]) - numbers.begin();
        g[i].emplace_back(idx, C);
        g[idx].emplace_back(i, 0LL);
    }

    get_dists(u - 1);

    long ans = dists[v - 1];
    cout << ans << "\n";
}