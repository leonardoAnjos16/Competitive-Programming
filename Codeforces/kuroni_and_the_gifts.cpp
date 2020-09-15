#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int b[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);

        sort(a, a + n);
        sort(b, b + n);

        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);

        printf("\n");
        for (int i = 0; i < n; i++)
            printf("%d ", b[i]);

        printf("\n");
    }
}