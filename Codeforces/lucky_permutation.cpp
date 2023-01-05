#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int cycles;
vector<int> p, vis, cycle;

void get_cycle(int v) {
    cycle[v] = cycles;

    int u = p[v];
    while (u != v) {
        cycle[u] = cycles;
        u = p[u];
    }

    cycles++;
}

void get_cycles(int v) {
    if (vis[v] == 2) return;
    if (vis[v] == 1) return get_cycle(v);

    vis[v] = 1;
    get_cycles(p[v]);
    vis[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        p.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        cycles = 0;
        vis.assign(n, 0);
        cycle.assign(n, -1);

        for (int i = 0; i < n; i++)
            get_cycles(i);

        int ans = INT_MAX;
        for (int i = 1; i < n; i++)
            ans = min(ans, n - (cycle[i - 1] == cycle[i] ? cycles + 1 : cycles - 1));

        cout << ans << "\n";
    }
}