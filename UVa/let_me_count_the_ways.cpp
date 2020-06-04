#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 3e4 + 5;

int coins[] = {1, 5, 10, 25, 50};
long memo[MAX][10];

long ways(int change, int i) {
    if (i >= 5) return 0LL;
    if (!change) return 1LL;
    if (memo[change][i] != -1) return memo[change][i];
    
    memo[change][i] = 0LL;
    for (int j = i; j < 5 && coins[j] <= change; j++)
        memo[change][i] += ways(change - coins[j], j);

    return memo[change][i];
}

int main() {
    int change;
    memset(memo, -1, sizeof memo);

    while (scanf("%d", &change) != EOF) {
        long ans = ways(change, 0);
        if (ans > 1) printf("There are %lld ways to produce %d cents change.\n", ans, change);
        else printf("There is only 1 way to produce %d cents change.\n", change);
    }
}