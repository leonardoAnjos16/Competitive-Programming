#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 5e3 + 5;

int N;
vector<vector<int>> g, dists;
bitset<MAX> vis;

void get_dists(int v) {
    dists[v].assign(N, 0);

    vis.reset();
    vis[v] = true;

    queue<int> aux;
    aux.push(v);

    while (!aux.empty()) {
        int u = aux.front(); aux.pop();
        for (auto w: g[u]) {
            if (!vis[w]) {
                aux.push(w);
                vis[w] = true;
                dists[v][w] = dists[v][u] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, K;
    cin >> N >> M >> K;

    g.assign(N, vector<int>());
    while (M--) {
        int u, v;
        cin >> u >> v;

        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    dists.resize(N);
    for (int i = 0; i < N; i++)
        get_dists(i);

    bool possible = true;
    for (int i = 0; i < N && possible; i++)
        for (int j = 0; j < N && possible; j++)
            if (dists[i][j] > N - K) possible = false;

    if (!possible) cout << "0\n";
    else {
        cout << N << "\n";
        for (int i = 0; i < N; i++) {
            if (i) cout << " ";
            cout << (i + 1);
        }

        cout << "\n";
    }
}