#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    vector<bool> seen(n, false);
    vector<pair<int, int>> queries(q);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 2) queries[i] = make_pair(op, -1);
        else {
            int v; cin >> v;
            seen[v - 1] = true;
            queries[i] = make_pair(op, v - 1);
        }
    }

    for (int i = 0; i < n; i++)
        if (!seen[i])
            queries.emplace_back(1, i);

    reverse(queries.begin(), queries.end());

    vector<vector<int>> ans;
    vector<int> status(n, 0);

    for (auto [op, v]: queries) {
        if (op == 2) {
            vector<int> corn;
            for (int i = 0; i < n; i++)
                if (status[i] == 1)
                    corn.push_back(i + 1);

            ans.push_back(corn);
        } else {
            int one = 0, two = 0;
            for (int u: g[v]) {
                if (status[u] == 1) two++;
                else if (status[u] == 2) one++;
            }

            status[v] = one > two ? 1 : 2;
        }
    }

    reverse(ans.begin(), ans.end());
    for (vector<int> &corn: ans) {
        int sz = corn.size();
        cout << sz;

        for (int v: corn)
            cout << " " << v;

        cout << "\n";
    }
}