#include <bits/stdc++.h>

using namespace std;

const int MAX = 35;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);

        int a[MAX], sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        int b[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);

        sort(a, a + n);
        sort(b, b + n, greater<int>());

        for (int i = 0; i < k; i++)
            if (b[i] > a[i]) sum += b[i] - a[i];

        printf("%d\n", sum);
    }
}