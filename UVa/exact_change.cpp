#include <bits/stdc++.h>

using namespace std;

const int MAX_SUM = 2e4 + 5;
const int MAX_N = 105;
const int INF = 1e6;

int n, A[MAX_N];
int memo[MAX_SUM][MAX_N];

int value(int s, int i = 0) {
    if (s <= 0) return 0;
    if (i >= n) return INF;

    if (memo[s][i] != -1) return memo[s][i];
    else return memo[s][i] = min(value(s, i + 1), A[i] + value(s - A[i], i + 1));
}

int coins(int s, int i = 0) {
    if (!s) return 0;
    if (s < 0 || i >= n) return INF;
    
    if (memo[s][i] != -1) return memo[s][i];
    else return memo[s][i] = min(coins(s, i + 1), 1 + coins(s - A[i], i + 1));
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int p; scanf("%d", &p);
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        memset(memo, -1, sizeof memo);
        int payed = value(p);

        memset(memo, -1, sizeof memo);
        int num_coins = coins(payed);

        printf("%d %d\n", payed, num_coins);
    }
}