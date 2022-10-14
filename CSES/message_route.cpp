#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<vector<int>> g;
vector<int> dist, parent;
 
void get_dists() {
    parent.assign(n, -1);
    dist.assign(n, -1);
    dist[0] = 0;
 
    queue<int> q;
    q.push(0);
 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
 
        for (int u: g[v])
            if (dist[u] == -1) {
                q.push(u);
                parent[u] = v;
                dist[u] = dist[v] + 1;
            }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int m;
    cin >> n >> m;
 
    g.assign(n, vector<int>());
    while (m--) {
        int a, b;
        cin >> a >> b;
 
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
 
    get_dists();
 
    int ans = dist[n - 1];
    if (ans == -1) cout << "IMPOSSIBLE\n";
    else {
        cout << (ans + 1) << "\n";
 
        int v = n - 1;
        vector<int> path;
 
        while (parent[v] != -1) {
            path.push_back(v + 1);
            v = parent[v];
        }
 
        path.push_back(1);
        reverse(path.begin(), path.end());
 
        for (int i = 0; i <= ans; i++) {
            if (i) cout << " ";
            cout << path[i];
        }
 
        cout << "\n";
    }
}