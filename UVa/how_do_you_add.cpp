#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
const int MOD = 1e6;

int memo[MAX][MAX];

int ways(int N, int K) {
    if (K == 1) return 1;
    if (memo[N][K] != -1) return memo[N][K];

    memo[N][K] = 0;
    for (int i = 0; i <= N; i++)
        memo[N][K] = (memo[N][K] + ways(N - i, K - 1)) % MOD;

    return memo[N][K];
}

int main() {
    int N, K;
    while (scanf("%d %d", &N, &K), N | K) {
        memset(memo, -1, sizeof memo);
        int ans = ways(N, K);
        printf("%d\n", ans);
    }
}