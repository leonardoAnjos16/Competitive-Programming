#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 3e4 + 5;

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long memo[MAX][11];

long ways(int m, int i = 0) {
    if (!m) return 1LL;

    long &ans = memo[m][i];
    if (ans != -1) return ans;

    ans = 0LL;
    for (int j = i; j < 11 && coins[j] <= m; j++)
        ans += ways(m - coins[j], j);

    return ans;
}

int main() {
    memset(memo, -1, sizeof memo);

    double amount;
    while (scanf("%lf", &amount), amount) {
        int money = floor(amount * 100 + .5);

        long ans = ways(money);
        printf("%6.2lf%17lld\n", amount, ans);
    }
}