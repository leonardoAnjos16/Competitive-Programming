#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n; scanf("%d", &n);

    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }

    printf("\n");
}