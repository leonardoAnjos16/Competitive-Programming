#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> tree;

void get_dists(vector<int> &dist, int node, int parent = -1) {
    for (int child: tree[node])
        if (child != parent) {
            dist[child] = dist[node] + 1;
            get_dists(dist, child, node);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k, c;
        cin >> n >> k >> c;

        tree.assign(n, vector<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        vector<int> d0(n, 0);
        get_dists(d0, 0);
        int a = max_element(d0.begin(), d0.end()) - d0.begin();

        vector<int> da(n, 0);
        get_dists(da, a);
        int b = max_element(da.begin(), da.end()) - da.begin();

        vector<int> db(n, 0);
        get_dists(db, b);

        llong ans = LLONG_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, 1LL * max(da[i], db[i]) * k - 1LL * d0[i] * c);

        cout << ans << "\n";
    }
}