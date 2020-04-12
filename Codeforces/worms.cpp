#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n; scanf("%d", &n);

    int a[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }

    int m; scanf("%d", &m);
    while (m--) {
        int q; scanf("%d", &q);

        int idx = lower_bound(a, a + n, q) - a;
        printf("%d\n", idx);
    }
}