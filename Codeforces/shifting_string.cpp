#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> p;
vector<bool> vis;
vector<vector<int>> cycles;

void get_cycle(int v) {
    vector<int> cycle;
    cycle.push_back(v);

    int u = p[v];
    while (u != v) {
        cycle.push_back(u);
        u = p[u];
    }

    cycles.push_back(cycle);
}

void get_cycles(int v = 0) {
    if (vis[v]) get_cycle(v);
    else {
        vis[v] = true;
        get_cycles(p[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        p.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        cycles.clear();
        vis.assign(n, false);

        for (int i = 0; i < n; i++)
            if (!vis[i]) get_cycles(i);

        vector<int> repeat;
        for (auto cycle: cycles) {
            string curr = "";
            for (int v: cycle)
                curr += s[v];

            int size = curr.size();
            curr += curr;

            int rotation = 0;
            bool found = false;

            while (rotation < size && !found)
                if (curr.substr(++rotation, size) == curr.substr(0, size))
                    found = true;

            repeat.push_back(rotation);
        }

        long ans = 1LL;
        for (int rotation: repeat) {
            long prod = ans * rotation;
            long g = gcd(ans, rotation);
            ans = prod / g;
        }

        cout << ans << "\n";
    }
}