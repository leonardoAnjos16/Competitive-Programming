#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 105;

int n, m;
vector<vector<int>> g;

stack<int> ans;
bitset<MAX> vis;

void toposort(int v) {
    if (vis[v]) return;

    vis[v] = true;
    for (auto u: g[v])
        toposort(u);

    ans.push(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m, n || m) {
        g.assign(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[--u].push_back(--v);
        }

        for (int i = 0; i < n; i++)
            toposort(i);

        while (!ans.empty()) {
            cout << ans.top() + 1; ans.pop();
            if (size(ans)) cout << " ";
        }

        cout << "\n";
        vis.reset();
        g.clear();
    }
}