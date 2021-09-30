#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e6 + 5;

bitset<MAX> vis;
vector<int> a, nxt;
vector<vector<int>> cycles;

void get_cycle(int v) {
    vector<int> cycle;
    cycle.push_back(v);

    int u = nxt[v];
    while (u != v) {
        cycle.push_back(u);
        u = nxt[u];
    }

    cycles.push_back(cycle);
}

void get_cycles(int v) {
    if (vis[v]) get_cycle(v);
    else {
        vis[v] = true;
        get_cycles(nxt[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;

        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        nxt.resize(n);
        for (int i = 0; i < n; i++)
            nxt[i] = (i + d) % n;

        vis.reset();
        cycles.clear();

        for (int i = 0; i < n; i++)
            if (!vis[i]) get_cycles(i);

        int ans = 0;
        bool possible = true;

        for (auto cycle: cycles) {
            int ones = 0, curr = 0;
            for (int i = 0; i < 2; i++)
                for (auto v: cycle) {
                    if (a[v]) curr++;
                    else {
                        ones = max(ones, curr);
                        curr = 0;
                    }
                }

            ones = max(ones, curr);
            if (ones >= (int) cycle.size()) {
                possible = false;
                break;
            }

            ans = max(ans, ones);
        }

        if (!possible) cout << "-1\n";
        else cout << ans << "\n";
    }
}