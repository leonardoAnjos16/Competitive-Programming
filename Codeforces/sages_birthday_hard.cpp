#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n; scanf("%d", &n);

    int A[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    sort(A, A + n);

    int ans[MAX], cnt = 0;
    for (int i = 1; i < n; i += 2)
        ans[i] = A[cnt++];

    for (int i = 0; i < n; i += 2)
        ans[i] = A[cnt++];

    cnt = 0;
    for (int i = 1; i < n - 1; i++)
        cnt += ans[i] < ans[i - 1] && ans[i] < ans[i + 1];

    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }

    printf("\n");
}