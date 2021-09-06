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
    cin >> N >> M;

    vector<vector<int>> g(N, vector<int>());
    while (M--) {
        int A, B;
        cin >> A >> B;
        g[A - 1].push_back(B - 1);
    }

    SCC scc(N, g);
    vector<int> component = scc.get_components();
    int num_components = *max_element(component.begin(), component.end()) + 1;

    vector<vector<int>> ng(num_components, vector<int>());
    for (int i = 0; i < N; i++)
        for (auto v: g[i])
            if (component[i] != component[v])
                ng[component[i]].push_back(component[v]);

    int cnt = 0, c = -1;
    for (int i = 0; i < num_components; i++)
        if (ng[i].empty()) cnt++, c = i;

    if (cnt > 1) cout << "0\n";
    else {
        vector<int> ans;
        for (int i = 0; i < N; i++)
            if (component[i] == c)
                ans.push_back(i + 1);

        cout << ((int) ans.size()) << "\n";
        for (int i = 0; i < (int) ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}