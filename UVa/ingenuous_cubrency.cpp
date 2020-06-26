#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e4 + 5;

int coins[21];
long memo[MAX][21];

long ways(int m, int i = 0) {
    if (!m) return 1LL;
    if (i >= 21) return 0LL;

    long &ans = memo[m][i];
    if (~ans) return ans;

    ans = 0;
    for (int j = i; j <= 21 && coins[j] <= m; j++)
        ans += ways(m - coins[j], j);

    return ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    for (int i = 1; i <= 21; i++)
        coins[i - 1] = i * i * i;

    int money;
    while (scanf("%d", &money) != EOF)
        printf("%lld\n", ways(money));
}