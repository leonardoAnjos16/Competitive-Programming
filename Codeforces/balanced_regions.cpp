#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 5e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int g; cin >> g;
    while (g--) {
        int n; cin >> n;
        vector<int> w(n);

        for (int i = 0; i < n; i++)
            cin >> w[i];

        int k; cin >> k;
        bitset<MAX> marked;

        for (int i = 0; i < k; i++) {
            int u; cin >> u;
            marked[u] = true;
        }

        int m; cin >> m;
        vector<vector<int>> g(n, vector<int>());

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g[x - 1].push_back(y - 1);
        }

        vector<int> v;
        for (int i = 1; i <= n; i++)
            if (!marked[i]) v.push_back(i);

        int q = v.size();
        cout << q;

        for (auto vi: v)
            cout << " " << vi;

        cout << "\n";

        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << "1 " << i << "\n";
    }
}