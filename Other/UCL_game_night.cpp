#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<vector<int>> P(N + 1, vector<int>(M + 1));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                cin >> P[i][j];

        vector<vector<int>> sum(N + 1, vector<int>(M + 1, 0));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                sum[i][j] = P[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

        int ans = 0;
        for (int lr = 1; lr <= N; lr++)
            for (int rr = lr; rr <= N; rr++)
                for (int lc = 1; lc <= M; lc++)
                    for (int rc = lc; rc <= M; rc++)
                        if (sum[rr][rc] - sum[rr][lc - 1] - sum[lr - 1][rc] + sum[lr - 1][lc - 1] <= K)
                            ans = max(ans, (rr - lr + 1) * (rc - lc + 1));

        cout << ans << "\n";
    }
}