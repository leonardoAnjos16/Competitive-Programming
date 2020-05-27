#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int l, n, c[MAX];
int memo[MAX][MAX];

int cost(int l, int r) {
    if (l + 1 == r) return 0;
    if (memo[l][r] != -1) return memo[l][r];

    memo[l][r] = INT_MAX;
    for (int i = l + 1; i < r; i++)
        memo[l][r] = min(memo[l][r], c[r] - c[l] + cost(l, i) + cost(i, r));

    return memo[l][r];
}

int main() {
    while (scanf("%d", &l), l) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &c[i]);

        c[0] = 0; c[n + 1] = l;
        memset(memo, -1, sizeof memo);

        int ans = cost(0, n + 1);
        printf("The minimum cutting is %d.\n", ans);
    }
}