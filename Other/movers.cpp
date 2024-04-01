#include <bits/stdc++.h>

using namespace std;

const int SQRT = 400;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> D(N);
    for (int i = 0; i < N; i++)
        cin >> D[i];

    vector<int> E(N);
    for (int i = 0; i < N; i++)
        cin >> E[i];

    vector<int> deg(N, 0);
    vector<vector<int>> g(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        deg[a - 1]++;
        deg[b - 1]++;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<int> light_desks(N, 0), light_monitors(N, 0);
    vector<vector<int>> heavy_neighbours(N, vector<int>());

    for (int i = 0; i < N; i++)
        for (int v: g[i]) {
            if (deg[v] > SQRT) heavy_neighbours[i].push_back(v);
            else {
                light_desks[i] += D[v];
                light_monitors[i] += E[v];
            }
        }

    while (Q--) {
        string op; cin >> op;
        if (op == "add") {
            string type;
            int count, label;
            cin >> count >> type >> label;

            if (type == "desk") D[label - 1] += count;
            else E[label - 1] += count;

            if (deg[label - 1] <= SQRT) {
                vector<int> &to_update = type == "desk" ? light_desks : light_monitors;
                for (int v: g[label - 1]) to_update[v] += count;
            }
        } else {
            int label; cin >> label;

            int desks = D[label - 1] + light_desks[label - 1];
            int monitors = E[label - 1] + light_monitors[label - 1];

            for (int v: heavy_neighbours[label - 1]) {
                desks += D[v];
                monitors += E[v];
            }

            cout << (desks == monitors ? "same" : ( desks > monitors ? "desks" : "monitors")) << "\n";
        }
    }
}