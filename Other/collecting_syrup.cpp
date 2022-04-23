#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<vector<int>> tree(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int syrup = s[i];
        for (auto v: tree[i])
            syrup += s[v];

        ans = max(ans, syrup);
    }

    cout << ans << "\n";
}