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

vector<llong> coins;
vector<vector<int>> g;
vector<llong> memo;

llong max_coins(int v) {
    llong &ans = memo[v];
    if (~ans) return ans;

    ans = 0LL;
    for (int u: g[v])
        ans = max(ans, max_coins(u));

    ans += coins[v];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];

    vector<vector<int>> tunnels(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        tunnels[a - 1].push_back(b - 1);
    }

    vector<int> components = SCC(n, tunnels).get_components();
    int num_components = *max_element(components.begin(), components.end()) + 1;

    coins.assign(num_components, 0LL);
    g.assign(num_components, vector<int>());

    for (int i = 0; i < n; i++) {
        coins[components[i]] += k[i];
        for (int v: tunnels[i])
            g[components[i]].push_back(components[v]);
    }

    memo.assign(num_components + 5, -1LL);

    llong ans = 0LL;
    for (int i = 0; i < num_components; i++)
        ans = max(ans, max_coins(i));

    cout << ans << "\n";
}