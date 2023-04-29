#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, E;
    cin >> N >> K >> E;

    vector<vector<int>> last(E + 1, vector<int>(N - E - K + 1));
    vector<vector<int>> curr(E + 1, vector<int>(N - E - K + 1));

    for (int i = 0; i <= E; i++)
        for (int j = 0; j <= N - E - K; j++)
            last[i][j] = i + j;

    for (int i = 1; i <= max(E, N - E - K); i++) {
        if (i == K) continue;

        for (int j = 0; j <= E; j++)
            for (int k = 0; k <= N - E - K; k++) {
                curr[j][k] = last[j][k];
                if (i <= j) curr[j][k] = min(curr[j][k], last[j - i][k]);
                if (i <= k) curr[j][k] = min(curr[j][k], last[j][k - i]);
            }

        last.swap(curr);
    }

    int ans = last[E][N - E - K];
    cout << ans << "\n";
}