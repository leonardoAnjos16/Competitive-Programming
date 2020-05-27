#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 25;

int main() {
    int t; scanf("%d", &t);
    int case_num = 0;

    while (t--) {
        if (case_num++) printf("\n");
        int A, B, C; scanf("%d %d %d", &A, &B, &C);

        long garbage[MAX][MAX][MAX];
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                for (int k = 0; k < C; k++)
                    scanf("%lld", &garbage[i][j][k]);

        long psum[MAX][MAX][MAX] = {0};
        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++)
                    psum[i][j][k] = garbage[i - 1][j - 1][k - 1] + psum[i][j - 1][k] + psum[i][j][k - 1] - psum[i][j - 1][k - 1];

        long ans = INT_MIN;
        for (int i = 1; i <= B; i++) { 
            for (int j = i; j <= B; j++) {
                for (int k = 1; k <= C; k++) {
                    for (int l = k; l <= C; l++) {
                        long sum = 0LL;
                        for (int m = 1; m <= A; m++) {
                            sum += psum[m][j][l] - psum[m][i - 1][l] - psum[m][j][k - 1] + psum[m][i - 1][k - 1];
                            ans = max(ans, sum);
                            if (sum < 0) sum = 0;
                        }
                    }
                }
            }
        }

        printf("%lld\n", ans);
    }
}