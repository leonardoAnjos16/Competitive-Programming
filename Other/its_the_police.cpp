#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    while (m--) {
        int a, b;
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<int> deg(n);
    for (int i = 0; i < n; i++)
        deg[i] = g[i].size();

    int best = 0;
    for (int i = 1; i < n; i++)
        if (deg[i] < deg[best])
            best = i;

    vector<int> ans(n, 1);
    ans[best] = 0;

    for (auto v: g[best])
        ans[v] = 0;

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}