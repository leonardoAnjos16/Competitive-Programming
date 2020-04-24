#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int n, c; scanf("%d %d", &n, &c);

    int a[MAX], b[MAX];
    for (int i = 1; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i < n; i++)
        scanf("%d", &b[i]);

    int ans[MAX][2] = {{0, c}};
    for (int i = 1; i < n; i++) {
        ans[i][0] = min(ans[i - 1][0], ans[i - 1][1]) + a[i];
        ans[i][1] = min(ans[i - 1][0] + c, ans[i - 1][1]) + b[i];
    }

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", min(ans[i][0], ans[i][1]));
    }

    printf("\n");
}