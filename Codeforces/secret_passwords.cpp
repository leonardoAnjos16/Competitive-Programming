#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 35;

int n;
vector<vector<int>> g;
bitset<MAX> vis;

void visit(int v) {
    vis[v] = true;
    for (auto u: g[v])
        if (!vis[u])
            visit(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    g.assign(26 + n, vector<int>());
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c: s) {
            g[c - 'a'].push_back(26 + i);
            g[26 + i].push_back(c - 'a');
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (!vis[26 + i])
            ans++, visit(26 + i);

    cout << ans << "\n";
}