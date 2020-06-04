#include <bits/stdc++.h>

using namespace std;

const int MAX = 305;
const int INF = 1e6;

int m, S, con[50], IT[50];
int memo[MAX][MAX];

int coins(int X = 0, int Y = 0) {
    if (X * X + Y * Y > S * S) return INF;
    if (X * X + Y * Y == S * S) return 0;
    if (memo[X][Y] != -1) return memo[X][Y];

    memo[X][Y] = INF;
    for (int i = 0; i < m; i++)
        memo[X][Y] = min(memo[X][Y], 1 + coins(X + con[i], Y + IT[i]));

    return memo[X][Y];
}

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &m, &S);
        for (int i = 0; i < m; i++)
            scanf("%d %d", &con[i], &IT[i]);

        memset(memo, -1, sizeof memo);

        int ans = coins();
        if (ans >= INF) printf("not possible\n");
        else printf("%d\n", ans);
    }
}