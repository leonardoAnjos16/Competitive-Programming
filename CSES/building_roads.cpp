#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> g;
vector<bool> vis;
 
void traverse(int v) {
    vis[v] = true;
    for (int u: g[v])
        if (!vis[u])
            traverse(u);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    g.assign(n, vector<int>());
    while (m--) {
        int a, b;
        cin >> a >> b;
 
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
 
    vis.assign(n, false);
 
    int cnt = 0, last = -1;
    vector<pair<int, int>> ans;
 
    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            cnt++;
            if (last != -1) ans.emplace_back(last + 1, i + 1);
            traverse(last = i);
        }
 
    cout << (cnt - 1) << "\n";
    for (auto [u, v]: ans)
        cout << u << " " << v << "\n";
}