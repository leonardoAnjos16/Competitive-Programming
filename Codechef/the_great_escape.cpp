#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 4e3 + 5;

int N;
vector<vector<int>> g;
vector<int> dists;

void get_dists(int v) {
    bitset<MAX> vis;
    vis[v] = true;

    dists.assign(N, -1);
    dists[v] = 0;

    queue<int> aux;
    aux.push(v);

    while (!aux.empty()) {
        v = aux.front();
        aux.pop();

        for (auto u: g[v]) {
            if (!vis[u]) {
                aux.push(u);
                vis[u] = true;
                dists[u] = dists[v] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M;

    g.assign(N, vector<int>());
    while (M--) {
        int A, B;
        cin >> A >> B;

        g[A - 1].push_back(B - 1);
        g[B - 1].push_back(A - 1);
    }

    int S, T;
    cin >> S >> T;

    get_dists(S - 1);

    int ans = dists[T - 1];
    if (ans == -1) ans = 0;

    cout << ans << "\n";
}