#include <bits/stdc++.h>

using namespace std;

const int MAX_DIFF = 5e4 + 5;
const int MAX_M = 105;

int m, coins[MAX_M];
int memo[MAX_DIFF][MAX_M];

int difference(int diff = 0, int i = 0) {
    if (i >= m) return diff;
    if (memo[diff][i] != -1) return memo[diff][i];
    return memo[diff][i] = min(difference(diff + coins[i], i + 1), difference(abs(diff - coins[i]), i + 1));
}

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            scanf("%d", &coins[i]);

        memset(memo, -1, sizeof memo);

        int ans = difference();
        printf("%d\n", ans);
    }
}