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

    int n, m, data_set = 1;
    while (cin >> n >> m, n || m) {
        if (data_set > 1) cout << "\n";

        int curr = 0;
        map<string, int> idx;
        map<int, string> name;

        vector<vector<int>> g(n, vector<int>());
        while (m--) {
            string u, v;
            cin >> u >> v;

            if (!idx.count(u)) {
                idx[u] = curr;
                name[curr++] = u;
            }

            if (!idx.count(v)) {
                idx[v] = curr;
                name[curr++] = v;
            }

            g[idx[u]].push_back(idx[v]);
        }

        SCC scc(n, g);
        vector<int> component = scc.get_components();
        int num_components = *max_element(component.begin(), component.end()) + 1;

        vector<vector<string>> ans(num_components, vector<string>());
        for (int i = 0; i < n; i++)
            ans[component[i]].push_back(name[i]);

        cout << "Calling circles for data set " << data_set++ << ":\n";
        for (int i = 0; i < num_components; i++) {
            for (int j = 0; j < (int) ans[i].size(); j++) {
                if (j) cout << ", ";
                cout << ans[i][j];
            }

            cout << "\n";
        }
    }
}