#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int c, m, x; scanf("%d %d %d", &c, &m, &x);

        x += max(c, m) - min(c, m);
        c = m = min(c, m);

        int groups = min(c, x);
        c -= groups; m -= groups; x -= groups;

        groups += (c + m) / 3;
        printf("%d\n", groups);
    }
}