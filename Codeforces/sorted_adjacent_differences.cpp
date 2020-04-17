#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        sort(a, a + n);

        int ans[MAX];
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) ans[i] = a[i / 2];
            else ans[i] = a[n - (i / 2) - 1];
        }

        reverse(ans, ans + n);

        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }

        printf("\n");
    }
}