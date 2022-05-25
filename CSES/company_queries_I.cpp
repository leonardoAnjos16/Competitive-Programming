#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 25;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> e(n, 0);
    for (int i = 1; i < n; i++)
        cin >> e[i];

    vector<vector<int>> up(LOG, vector<int>(n));
    for (int i = 0; i < n; i++)
        up[0][i] = e[i] - 1;

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < n; j++) {
            if (up[i - 1][j] == -1) up[i][j] = -1;
            else up[i][j] = up[i - 1][up[i - 1][j]];
        }

    while (q--) {
        int x, k;
        cin >> x >> k;

        int ans = x - 1;
        for (int i = 0; i < LOG && ans != -1; i++)
            if (k & (1 << i)) ans = up[i][ans];

        if (ans == -1) cout << "-1\n";
        else cout << (ans + 1) << "\n";
    }
}