#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(6) << fixed;

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<vector<ldouble>> dp(N + 5, vector<ldouble>(N + 5, 0.0L));
        dp[0][0] = 1.0L;

        for (int i = 0; i < N; i++) {
            for (int j = 0; i + j <= N; j++) {
                int k = N - i - j;
                ldouble p = 2.0L * k / (2.0L * k + j);

                dp[i][j + 1] += dp[i][j] * p;
                if (j) dp[i + 1][j - 1] += dp[i][j] * (1 - p);
            }
        }

        ldouble sum = 0.0L;
        for (int i = 0; K + i <= N; i++)
            sum += dp[K][i];

        ldouble ans = 2.0L * N;
        for (int i = 0; K + i <= N; i++)
            ans -= dp[K][i] / sum * (2.0L * K + i);

        cout << ans << "\n";
    }
}