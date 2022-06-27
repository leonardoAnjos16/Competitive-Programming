#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, K;
    cin >> M >> N >> K;

    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= M; i++)
        dp[i][0] = i;

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
        }

    bool possible = false;
    for (int i = 1; i <= N && !possible; i++)
        if (dp[M][i] <= K) possible = true;
    
    cout << (possible ? "S" : "N") << "\n";
}