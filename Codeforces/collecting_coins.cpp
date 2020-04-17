#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b, c, n;
        scanf("%d %d %d %d", &a, &b, &c, &n);

        int coins[3] = {a, b, c};
        sort(coins, coins + 3, greater<int>());;

        int aux = coins[0] * 2 - coins[1] - coins[2];
        if (n < aux || (n - aux) % 3) printf("NO\n");
        else printf("YES\n");
    }
}