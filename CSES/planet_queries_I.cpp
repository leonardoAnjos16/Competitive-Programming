#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 30;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    vector<vector<int>> up(LOG, vector<int>(n));
    for (int i = 0; i < n; i++)
        up[0][i] = t[i] - 1;

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < n; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];

    while (q--) {
        int x, k;
        cin >> x >> k;

        int ans = x - 1;
        for (int i = 0; i < LOG; i++)
            if (k & (1 << i))
                ans = up[i][ans];

        cout << (ans + 1) << "\n";
    }
}