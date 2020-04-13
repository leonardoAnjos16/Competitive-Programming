#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, d; scanf("%d %d", &n, &d);

        int a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        for (int i = 1; i < n; i++) {
            int aux = min(d / i, a[i]);
            a[0] += aux; d -= i * aux;
        }

        printf("%d\n", a[0]);
    }
}