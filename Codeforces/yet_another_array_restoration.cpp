#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);

        int diff = y - x, max_div = 1;
        for (int i = 1; i < min(diff, n - 1); i++)
            if (diff % (i + 1) == 0) max_div = i + 1;

        int step = diff / max_div;
        printf("%d", x); n--;

        for (int i = x + step; i <= y; i += step, n--)
            printf(" %d", i);

        for (int i = x - step; i > 0 && n; i -= step, n--)
            printf(" %d", i);

        for (int i = y + step; n; i += step, n--)
            printf(" %d", i);

        printf("\n");
    }
}