#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n, k, cycles = 0;
vector<int> x, component, vis, cnt;
vector<pair<int, int>> components;
vector<vector<int>> memo;

void get_cycle(int v) {
    component[v] = cycles;
    vector<int> cycle = { v };

    int u = x[v] - 1;
    while (u != v) {
        cycle.push_back(u);
        component[u] = cycles;
        u = x[u] - 1;
    }

    int size = cycle.size();
    for (auto u: cycle)
        cnt[u] = size;

    cycles++;
}

void get_cycles(int v) {
    if (vis[v] == 2) return;

    if (vis[v] == 1) get_cycle(v);
    else {
        vis[v] = 1;
        get_cycles(x[v] - 1);
        vis[v] = 2;
    }
}

void get_component_and_cnt(int v) {
    if (component[v] != -1) return;

    get_component_and_cnt(x[v] - 1);
    component[v] = component[x[v] - 1];
    cnt[v] = cnt[x[v] - 1] + 1;
}

int participants(int cycle = 0, int chosen = 0) {
    if (chosen > k) return INT_MIN;
    if (cycle >= cycles) return chosen;

    int &ans = memo[cycle][chosen];
    if (~ans) return ans;

    auto [mn, size] = components[cycle];
    ans = participants(cycle + 1, chosen);

    for (int i = mn; i <= size; i++)
        ans = max(ans, participants(cycle + 1, chosen + i));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    x.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    component.assign(n, -1);
    cnt.assign(n, -1);
    vis.assign(n, 0);

    for (int i = 0; i < n; i++)
        if (!vis[i]) get_cycles(i);

    for (int i = 0; i < n; i++)
        get_component_and_cnt(i);

    vector<int> mn(cycles, INT_MAX), size(cycles, 0);
    for (int i = 0; i < n; i++) {
        mn[component[i]] = min(mn[component[i]], cnt[i]);
        size[component[i]]++;
    }

    for (int i = 0; i < cycles; i++)
        components.emplace_back(mn[i], size[i]);

    memo.assign(cycles, vector<int>(k + 1, -1));

    int ans = participants();
    cout << ans << "\n";
}