#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<vector<int>> g;

vector<int> toposort() {
    vector<int> deg(N, 0);
    for (int i = 0; i < N; i++)
        for (auto v: g[i])
            deg[v]++;

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < N; i++)
        if (!deg[i]) heap.push(i);

    vector<int> order;
    while (!heap.empty()) {
        int v = heap.top(); heap.pop();
        order.push_back(v);

        for (auto u: g[v])
            if (--deg[u] == 0)
                heap.push(u);
    }

    return order;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_case = 1;
    while (cin >> N) {
        map<string, int> idx;
        vector<string> drinks(N);
        g.assign(N, vector<int>());

        for (int i = 0; i < N; i++) {
            string drink; cin >> drink;
            idx[drink] = i;
            drinks[i] = drink;
        }

        int M; cin >> M;
        while (M--) {
            string u, v;
            cin >> u >> v;
            g[idx[u]].push_back(idx[v]);
        }

        vector<int> order = toposort();

        cout << "Case #" << num_case++ << ": Dilbert should drink beverages in this order:";
        for (auto v: order)
            cout << " " << drinks[v];

        cout << ".\n\n";
    }
}