#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a[MAX];
        for (int i = 0; i < n << 1; i++)
            scanf("%d", &a[i]);

        bitset<MAX> seen;
        int ans[MAX], cnt = 0;

        for (int i = 0; cnt < n; i++)
            if (!seen[a[i]]) {
                ans[cnt++] = a[i];
                seen[a[i]] = true;
            }

        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }

        printf("\n");
    }
}