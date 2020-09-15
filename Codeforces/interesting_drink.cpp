#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n; scanf("%d", &n);

    int x[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    sort(x, x + n);

    int q; scanf("%d", &q);
    while (q--) {
        int m; scanf("%d", &m);

        int ans = upper_bound(x, x + n, m) - x;
        printf("%d\n", ans);
    }
}