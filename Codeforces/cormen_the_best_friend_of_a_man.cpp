#include <bits/stdc++.h>

using namespace std;

const int MAX = 505;

int main() {
    int n, k; scanf("%d %d", &n, &k);

    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int add_walks = 0;
    for (int i = 1; i < n; i++) {
        int add = max(0, k - (a[i] + a[i - 1]));
        a[i] += add; add_walks += add;
    }

    printf("%d\n", add_walks);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }

    printf("\n");
}