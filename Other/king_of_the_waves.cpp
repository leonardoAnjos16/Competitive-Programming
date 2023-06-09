#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> g;
vector<bool> vis;
vector<int> ans;

void visit(int v = 0) {
    if (vis[v]) return;

    vis[v] = true;
    ans.push_back(v);

    for (int u: g[v])
        visit(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    g.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        string win; cin >> win;
        for (int j = 0; j < n; j++)
            if (win[j] == '1')
                g[i].push_back(j);
    }

    vis.assign(n, false);
    visit();

    bool possible = (int) ans.size() == n;
    if (!possible) cout << "impossible\n";
    else {
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}