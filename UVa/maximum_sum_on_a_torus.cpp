#include <bits/stdc++.h>

using namespace std;

const int MAX = 200;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int N; scanf("%d", &N);

        int A[MAX][MAX];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &A[i][j]);
                A[i + N][j + N] = A[i + N][j] = A[i][j + N] = A[i][j];
            }
        }

        N <<= 1;
        int psum[MAX][MAX] = {0};

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                psum[i][j] = A[i - 1][j - 1] + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];

        int ans = INT_MIN;
        for (int i = 1; i <= N >> 1; i++) for (int j = i; j <= N && j - i + 1 <= N >> 1; j++)
            for (int k = 1; k <= N >> 1; k++) for (int l = k; l <= N && l - k + 1 <= N >> 1; l++)
                ans = max(ans, psum[j][l] - psum[j][k - 1] - psum[i - 1][l] + psum[i - 1][k - 1]);

        printf("%d\n", ans);
    }
}