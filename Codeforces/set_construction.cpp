#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> deg(n, 0);
        vector<vector<int>> g(n, vector<int>());

        for (int i = 0; i < n; i++) {
            string bi; cin >> bi;
            for (int j = 0; j < n; j++)
                if (bi[j] == '1') {
                    deg[j]++;
                    g[i].push_back(j);
                }
        }

        int start = 1;
        vector<set<int>> ans(n);

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!deg[i]) {
                ans[i].insert(start++);
                q.push(i);
            }

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u: g[v]) {
                for (int w: ans[v])
                    ans[u].insert(w);

                if (--deg[u] == 0) {
                    ans[u].insert(start++);
                    q.push(u);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int s = ans[i].size();
            cout << s;

            for (int v: ans[i])
                cout << " " << v;

            cout << "\n";
        }
    }
}