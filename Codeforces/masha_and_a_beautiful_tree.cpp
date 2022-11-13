#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int m; cin >> m;

        vector<int> p(m);
        for (int i = 0; i < m; i++)
            cin >> p[i];

        vector<vector<int>> mns(1, p);
        for (int i = 1; (1 << i) < m; i++) {
            vector<int> aux(m);
            for (int j = 0; j < m; j++) {
                if (j + (1 << (i - 1)) >= m) aux[j] = mns[i - 1][j];
                else aux[j] = min(mns[i - 1][j], mns[i - 1][j + (1 << (i - 1))]);
            }

            mns.push_back(aux);
        }

        int ans = 0;
        bool possible = true;

        for (int i = 0; (1 << i) < m && possible; i++)
            for (int j = 0; j < m && possible; j += (2 << i)) {
                int l = mns[i][j], r = mns[i][j + (1 << i)];
                if (abs(r - l) != (1 << i)) possible = false;
                else if (l > r) ans++;
            }

        if (!possible) cout << "-1\n";
        else cout << ans << "\n";
    }
}