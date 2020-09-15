#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int k, n, a, b;
        scanf("%d %d %d %d", &k, &n, &a, &b);

        long bn = (b * 1LL) * n;

        if (k <= bn) printf("-1\n");
        else {
            int c = (k - bn - 1) / (a - b);
            if (c > n) c = n;

            printf("%d\n", c);
        }
    }
}