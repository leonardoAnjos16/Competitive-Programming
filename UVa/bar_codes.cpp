#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 55;

int n, k, m;
long memo[MAX][MAX];

long symbols(int units, int bar) {
    if (!units && bar >= k) return 1LL;
    if (!units || bar >= k) return 0LL;

    long &ans = memo[units][bar];
    if (ans != -1) return ans;

    ans = 0LL;
    for (int i = 1; i <= min(units, m); i++)
        ans += symbols(units - i, bar + 1);

    return ans;
}

int main() {
    while (scanf("%d %d %d", &n, &k, &m) != EOF) {
        memset(memo, -1, sizeof memo);
        long ans = symbols(n, 0);
        printf("%lld\n", ans);
    }
}