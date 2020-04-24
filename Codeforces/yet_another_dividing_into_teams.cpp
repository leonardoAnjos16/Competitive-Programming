#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int n; scanf("%d", &n);

        int a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        sort(a, a + n);

        int ans = 1;
        for (int i = 1; i < n && ans < 2; i++)
            if (a[i] - a[i - 1] == 1) ans++;

        printf("%d\n", ans);
    }
}