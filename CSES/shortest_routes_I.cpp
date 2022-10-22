#include <bits/stdc++.h>
 
using namespace std;
 
const long long int INF = 1e18 + 5;
 
int n;
vector<vector<pair<int, int>>> g;
vector<long long int> dists;
 
void get_dists() {
    vector<bool> vis(n, false);
    dists.assign(n, INF);
    dists[0] = 0LL;
 
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> heap;
    heap.emplace(0LL, 0);
 
    while (!heap.empty()) {
        auto [cost, v] = heap.top(); heap.pop();
        if (vis[v]) continue;
        vis[v] = true;
 
        for (auto [u, c]: g[v])
            if (!vis[u] && dists[v] + c < dists[u]) {
                dists[u] = dists[v] + c;
                heap.emplace(dists[u], u);
            }
    }
}
 
int main() {
    int m;
    cin >> n >> m;
 
    g.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].emplace_back(b - 1, c);
    }
 
    get_dists();
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << dists[i];
    }
 
    cout << "\n";
}