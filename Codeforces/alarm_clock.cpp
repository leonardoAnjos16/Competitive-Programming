#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        long ans = b;
        a -= b;

        if (a <= 0) printf("%lld\n", ans);
        if (a > 0) {
            if (c <= d) printf("-1\n");
            else {
                int aux = ceil((a + .0) / (c - d));
                ans += (long) aux * c;

                printf("%lld\n", ans);
            }
        }
    }
}