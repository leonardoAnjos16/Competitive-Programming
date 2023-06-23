#include <bits/stdc++.h>

using namespace std;

#define llong long long int

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
    cin >> N >> M;

    vector<vector<int>> g(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int R, S;
        cin >> R >> S;
        g[R - 1].emplace_back(S - 1);
    }

    vector<int> component = SCC(N, g).get_components();
    int num_components = *max_element(component.begin(), component.end()) + 1;

    if (num_components == 1) cout << "0\n";
    else {
        vector<int> in(num_components, 0), out(num_components, 0);
        for (int i = 0; i < N; i++)
            for (int v: g[i])
                if (component[i] != component[v]) {
                    in[component[v]]++;
                    out[component[i]]++;
                }

        int need_in = 0, need_out = 0;
        for (int i = 0; i < num_components; i++) {
            if (!in[i]) need_in++;
            if (!out[i]) need_out++;
        }

        int ans = max(need_in, need_out);
        cout << ans << "\n";
    }
}