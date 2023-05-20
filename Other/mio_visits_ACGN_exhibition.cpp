#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    vector<vector<int>> cnt(m);
    cnt[0].resize(2);
    cnt[0][0] = A[0][0];
    cnt[0][1] = !A[0][0];

    for (int i = 1; i < m; i++) {
        int v = !A[0][i];
        cnt[i].assign(i + 2, 0);

        for (int j = 0; j <= i; j++)
            cnt[i][j + v] = cnt[i - 1][j];
    }

    for (int i = 1; i < n; i++) {
        vector<vector<int>> curr(m);
        curr[0].assign(i + 2, 0);

        int v = !A[i][0];
        for (int j = 0; j <= i; j++)
            curr[0][j + v] = cnt[0][j];

        for (int j = 1; j < m; j++) {
            v = !A[i][j];
            curr[j].assign(i + j + 2, 0);

            for (int k = 0; k <= i + j; k++) {
                curr[j][k + v] = (curr[j][k + v] + cnt[j][k]) % MOD;
                curr[j][k + v] = (curr[j][k + v] + curr[j - 1][k]) % MOD;
            }
        }

        cnt = curr;
    }

    int ans = 0;
    for (int i = p; i < n + m; i++)
        if (n + m - i - 1 >= q)
            ans = (ans + cnt[m - 1][i]) % MOD;

    cout << ans << "\n";
}