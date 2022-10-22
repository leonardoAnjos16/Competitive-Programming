#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> color;
vector<vector<int>> g;
 
bool bicolorable(int v, int c = 0) {
    if (color[v] == c) return true;
    if (color[v] != -1) return false;
 
    color[v] = c;
    for (int u: g[v])
        if (!bicolorable(u, 1 - c))
            return false;
 
    return true;
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
 
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
 
    color.assign(n, -1);
 
    bool possible = true;
    for (int i = 0; i < n && possible; i++)
        if (color[i] == -1 && !bicolorable(i))
            possible = false;
 
    if (!possible) cout << "IMPOSSIBLE\n";
    else {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << (color[i] + 1);
        }
 
        cout << "\n";
    }
}