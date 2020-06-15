#include <bits/stdc++.h>

using namespace std;

#define pair pair<int, int>
#define l first
#define m second

const int MAX = 1e4 + 5;

int LIS(pair A[MAX], int n) {
    int dp[MAX], len = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (A[j].l <= A[i].l && A[j].m <= A[i].m)
                dp[i] = max(dp[i], 1 + dp[j]);

        len = max(len, dp[i]);
    }

    return len;
}

int main() {
    int n;
    while (scanf("%d", &n), n) {
        pair B[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d %d", &B[i].l, &B[i].m);

        sort(B, B + n);

        int ans = LIS(B, n);
        printf("%d\n", ans);
    }

    printf("*\n");
}