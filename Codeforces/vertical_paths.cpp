#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        if (n == 1) {
            int aux; cin >> aux;
            cout << "1\n1\n1\n";
        } else {
            vector<int> p(n);
            for (int i = 0; i < n; i++)
                cin >> p[i];

            vector<bool> parent(n, false);
            for (int i = 0; i < n; i++)
                parent[p[i] - 1] = true;

            int cnt = 0, idx = 0;
            vector<bool> used(n, false);
            vector<vector<int>> ans;

            while (cnt < n) {
                while (idx < n && parent[idx]) idx++;
                assert(idx < n);

                int v = idx++;
                vector<int> path;

                while (!used[v]) {
                    path.push_back(v + 1);
                    used[v] = true;
                    v = p[v] - 1;
                    cnt++;
                }

                reverse(path.begin(), path.end());
                ans.push_back(path);
            }

            int size = ans.size();
            cout << size << "\n";

            for (auto path: ans) {
                size = path.size();
                cout << size << "\n";

                for (int i = 0; i < size; i++) {
                    if (i) cout << " ";
                    cout << path[i];
                }

                cout << "\n";
            }
        }

        if (t) cout << "\n";
    }
}