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

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> g(m, vector<int>());
        while (n--) {
            int a, b;
            cin >> a >> b;
            g[a - 1].push_back(b - 1);
        }

        SCC scc(m, g);
        vector<int> component = scc.get_components();
        int num_components = *max_element(component.begin(), component.end()) + 1;

        vector<vector<int>> ng(num_components, vector<int>());
        for (int i = 0; i < m; i++)
            for (auto v: g[i])
                if (component[i] != component[v])
                    ng[component[i]].push_back(component[v]);

        vector<int> deg(num_components, 0);
        for (int i = 0; i < num_components; i++)
            for (auto v: ng[i]) deg[v]++;

        int ans = 0;
        for (int i = 0; i < num_components; i++)
            if (!deg[i]) ans++;

        cout << "Case " << t << ": " << ans << "\n";
    }
}