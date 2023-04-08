#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int N;
vector<vector<int>> tree;
vector<llong> paths;
vector<int> c, sz;

void init(int v, int node = 0, int parent = -1) {
    sz[node] = 1;
    paths[node] = 0LL;

    for (int child: tree[node])
        if (child != parent) {
            init(v + c[child], child, node);
            paths[node] += 1LL * sz[child] * sz[node];
            sz[node] += sz[child];
        }

    paths[node] += 1LL * sz[node] * (N - sz[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> N >> K;

    c.resize(N);
    for (int i = 0; i < N; i++)
        cin >> c[i];

    tree.assign(N, vector<int>());
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    sz.resize(N);
    paths.resize(N);
    init(c[0]);

    priority_queue<pair<llong, int>> heap;
    for (int i = 0; i < N; i++)
        if (paths[i])
            heap.emplace(paths[i], i);

    while (K && !heap.empty()) {
        int aux = min(K, c[heap.top().second]);
        c[heap.top().second] -= aux;
        heap.pop();
        K -= aux;
    }

    llong ans = 0LL;
    for (int i = 0; i < N; i++)
        ans += 2LL * paths[i] * c[i];

    cout << ans << "\n";
}