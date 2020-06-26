#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 8e3 + 5;

int coins[5] = {1, 5, 10, 25, 50};
int memo[MAX][5];

long ways(int m, int i = 0) {
    if (!m) return 1LL;
    if (i >= 5) return 0LL;

    int &ans = memo[m][i];
    if (~ans) return ans;

    ans = 0;
    for (int j = i; j < 5 && coins[j] <= m; j++)
        ans += ways(m - coins[j], j);

    return ans;
}

int main() {
    memset(memo, -1, sizeof memo);

    int money;
    while (scanf("%d", &money) != EOF)
        printf("%lld\n", ways(money));
}