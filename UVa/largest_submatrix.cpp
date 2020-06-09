#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;

int main() {
    int t; scanf("%d", &t);
    bool first = true;
    while (t--) {
        if (!first) printf("\n");
        else first = false;

        char A[MAX][MAX];
        scanf("%s", A[0]);

        int N = strlen(A[0]);
        for (int i = 1; i < N; i++)
            scanf("%s", A[i]);

        int psum[MAX][MAX] = {0};
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                psum[i][j] = A[i - 1][j - 1] - '0' + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                for (int k = 1; k <= N; k++) {
                    for (int l = k; l <= N; l++) {
                        int sum = psum[j][l] - psum[i - 1][l] - psum[j][k - 1] + psum[i - 1][k - 1];
                        if (sum == (j - i + 1) * (l - k + 1)) ans = max(ans, sum);
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
}