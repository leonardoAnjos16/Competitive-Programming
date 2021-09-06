#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SCC {
private:
    int n;
    stack<int> order;
    vector<bool> vis;
    vector<int> component;
    vector<vector<int>> g, gt;

public:
    SCC(int n, vector<vector<int>> &g) {
        this->n = n;
        this->g = g;

        gt.assign(n, vector<int>());
        for (int i = 0; i < n; i++)
            for (auto v: g[i])
                gt[v].push_back(i);
    }

    vector<int> get_components() {
        vis.assign(n, false);
        for (int i = 0; i < n; i++)
            if (!vis[i]) toposort(i);

        int idx = 0;
        component.assign(n, -1);

        while (!order.empty()) {
            int v = order.top(); order.pop();
            if (component[v] == -1)
                get_component(v, idx++);
        }

        return component;
    }

private:
    void toposort(int v) {
        if (vis[v]) return;
        vis[v] = true;

        for (auto u: g[v])
            toposort(u);

        order.push(v);
    }

    void get_component(int v, int c) {
        if (~component[v]) return;
        component[v] = c;

        for (auto u: gt[v])
            get_component(u, c);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M, N || M) {
        vector<vector<int>> g(N, vector<int>());
        while (M--) {
            int V, W, P;
            cin >> V >> W >> P;

            g[V - 1].push_back(W - 1);
            if (P == 2)
                g[W - 1].push_back(V - 1);
        }

        SCC scc(N, g);
        vector<int> component = scc.get_components();
        int num_components = *max_element(component.begin(), component.end()) + 1;

        bool ans = num_components == 1;
        cout << ans << "\n";
    }
}