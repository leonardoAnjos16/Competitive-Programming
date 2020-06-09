#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int N, M; bool first = true;
    while (scanf("%d %d", &N, &M) != EOF) {
        if (!first) printf("\n");
        else first = false;

        int A[MAX][MAX];
        for (int i = N; i > 0; i--)
            for (int j = 1; j <= N; j++)
                scanf("%d", &A[i][j]);

        int psum[MAX][MAX] = {0};
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                psum[i][j] = A[i][j] + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];

        for (int i = 0; i <= N - M; i++)
            for (int j = 0; j <= N - M; j++)
                A[i][j] = psum[i + M][j + M] - psum[i][j + M] - psum[i + M][j] + psum[i][j];

        int sum = 0;
        for (int i = N - M; i >= 0; i--) {
            for (int j = 0; j <= N - M; j++) {
                sum += A[i][j];
                printf("%d\n", A[i][j]);
            }
        }

        printf("%d\n", sum);
    }
}