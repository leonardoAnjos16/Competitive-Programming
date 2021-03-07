#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

vector<vi> g;

set<int> vis;
set<int> tree;
stack<int> ans;

bool toposort(int v) {
    if (tree.count(v)) return false;
    if (vis.count(v)) return true;

    vis.insert(v);
    tree.insert(v);

    for (auto u: g[v])
        if (!toposort(u))
            return false;

    ans.push(v);
    tree.erase(v);

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m, n || m) {
        g.assign(n, vi());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[--u].pb(--v);
        }

        bool possible = true;
        for (int i = 0; i < n && possible; i++)
            if (!vis.count(i) && !toposort(i)) possible = false;

        if (!possible) cout << "IMPOSSIBLE\n";
        else {
            while (!ans.empty())
                cout << (ans.top() + 1) << "\n", ans.pop();
        }

        g.clear();
        vis.clear();
        tree.clear();
        ans = stack<int>();
    }
}