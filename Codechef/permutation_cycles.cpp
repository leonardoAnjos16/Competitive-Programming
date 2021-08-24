#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e3 + 5;

vector<int> g, comp;
bitset<MAX> vis;

void dfs(int v) {
    vis[v] = true;
    comp.push_back(v);

    if (!vis[g[v]])
        dfs(g[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    g.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> g[i];

    int ans = 0;
    vector<vector<int>> cycles;

    for (int i = 1; i <= N; i++)
        if (!vis[i]) {
            comp.clear();
            dfs(i); ans++;
            comp.push_back(i);
            cycles.push_back(comp);
        }

    cout << ans << "\n";
    for (auto c: cycles) {
        for (int i = 0; i < (int) c.size(); i++) {
            if (i) cout << " ";
            cout << c[i];
        }

        cout << "\n";
    }
}