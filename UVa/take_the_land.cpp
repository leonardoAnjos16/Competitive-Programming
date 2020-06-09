#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int M, N;
    while (scanf("%d %d", &M, &N), M | N) {
        int psum[MAX][MAX] = {0};
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &psum[i][j]);
                psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = i; j <= M; j++) {
                for (int k = 1; k <= N; k++) {
                    for (int l = k; l <= N; l++) {
                        int sum = psum[j][l] - psum[i - 1][l] - psum[j][k - 1] + psum[i - 1][k - 1];
                        if (!sum) ans = max(ans, (j - i + 1) * (l - k + 1));
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
}