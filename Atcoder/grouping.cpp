#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<vector<long>> a(N, vector<long>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    vector<long> scores(1 << N, 0LL);
    for (int i = 1; i < (1 << N); i++) {
        vector<int> group;
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                group.push_back(j);

        for (auto j: group)
            for (auto k: group)
                scores[i] += a[j][k];

        scores[i] >>= 1LL;
    }

    vector<long> dp(1 << N, 0LL);
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j <= i; j++)
            if ((i | j) == i)
                dp[i] = max(dp[i], scores[j] + dp[i ^ j]);

    long ans = dp[(1 << N) - 1];
    cout << ans << "\n";
}