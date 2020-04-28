#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int x, y; scanf("%d %d", &x, &y);
        int a, b; scanf("%d %d", &a, &b);

        long ans = (long) abs(x - y) * a;
        ans += b > 2 * a ? 2LL * a * min(x, y) : (long) b * min(x, y);

        printf("%lld\n", ans);
    }
}