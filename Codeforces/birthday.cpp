#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n; scanf("%d", &n);

    int A[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    sort(A, A + n);

    int ans[MAX];
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) ans[i / 2] = A[i];
        else ans[n - ((i + 1) / 2)] = A[i];
    }

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }

    printf("\n");
}