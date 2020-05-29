#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int A[MAX][MAX], psum[MAX][MAX] = {0};
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &A[i][j]);
                psum[i][j] = A[i][j] + psum[i][j - 1];
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                int sum = 0;
                for (int k = 1; k <= N; k++) {
                    sum += psum[k][j] - psum[k][i - 1];
                    ans = max(ans, sum);
                    if (sum < 0) sum = 0;
                }
            }
        }

        printf("%d\n", ans);
    }
}