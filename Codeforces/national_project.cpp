#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, g, b; scanf("%d %d %d", &n, &g, &b);

        long x = ceil(n / 2.0);
        long y = max(0LL, (long) ceil(x / (g + 0.0)) - 1) * b;
        long z = max(0LL, n - x - y);

        long d = x + y + z;
        printf("%lld\n", d);
    }
}