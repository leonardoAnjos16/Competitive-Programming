#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 360;

int nxt[MAX];
bitset<MAX> vis;
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

    int N; cin >> N;

    bitset<MAX> pos;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        pos[a] = true;
    }

    int ans = 0;
    for (int i = 1; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            nxt[j] = (j - i + MAX) % MAX;

        vis.reset();
        cycles.clear();

        for (int j = 0; j < MAX; j++)
            if (!vis[j]) get_cycles(j);

        int cnt = 0;
        for (auto cycle: cycles) {
            int sz = cycle.size();

            int first = 0;
            while (first < sz && pos[cycle[first]])
                first++;

            if (first >= sz) cnt += sz / 2;
            else {
                int ones = 0, curr = first, seen = 0;
                while (seen++ < sz) {
                    if (pos[cycle[curr]]) ones++;
                    else {
                        cnt += ones / 2;
                        ones = 0;
                    }

                    curr = (curr + 1) % sz;
                }

                cnt += ones / 2;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << "\n";
}