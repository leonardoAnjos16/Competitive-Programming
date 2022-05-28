#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<vector<long double>> p(n, vector<long double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];

    vector<pair<int, int>> order(1 << n);
    for (int i = 0; i < (1 << n); i++)
        order[i] = make_pair(__builtin_popcount(i), i);

    sort(order.rbegin(), order.rend());

    vector<vector<long double>> dp(1 << n, vector<long double>(n));
    for (int i = 1; i < (1 << n); i++) {
        auto [cnt, mask] = order[i];
        if (cnt == n - 1) {
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) dp[mask][j] = 0.0L;
                else dp[mask][j] = 1.0L;
            }
        } else {
            for (int j = 0; j < n; j++)
                dp[mask][j] = 0.0L;

            int total = 0;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                for (int k = 0; k < n; k++) {
                    if (j == k || (mask & (1 << k))) continue;

                    for (int l = 0; l < n; l++) {
                        dp[mask][l] += dp[mask | (1 << j)][l] * p[k][j];
                        dp[mask][l] += dp[mask | (1 << k)][l] * p[j][k];
                    }

                    total++;
                }
            }

            for (int j = 0; j < n; j++)
                dp[mask][j] /= total;
        }
    }

    vector<long double> &ans = dp[0];
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";
}