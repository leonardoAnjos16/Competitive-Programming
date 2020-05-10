#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);

        int aux = k - 1;
        if (n > aux && (n - aux) & 1) {
            printf("YES\n");
            for (int i = 1; i < k; i++)
                printf("1 ");

            printf("%d\n", n - aux);
        } else if (n > 2 * aux && !((n - 2 * aux) & 1)) {
            printf("YES\n");
            for (int i = 1; i < k; i++)
                printf("2 ");

            printf("%d\n", n - 2 * aux);
        }
        else printf("NO\n");
    }
}