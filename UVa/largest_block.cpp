#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int p; scanf("%d", &p);
    while (p--) {
        int s; scanf("%d", &s);
        int b; scanf("%d", &b);

        int A[MAX][MAX] = {0};
        while (b--) {
            int r1, c1, r2, c2;
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

            for (int i = r1; i <= r2; i++)
                for (int j = c1; j <= c2; j++)
                    A[i][j] = 1;
        }

        int psum[MAX][MAX] = {0};
        for (int i = 1; i <= s; i++)
            for (int j = 1; j <= s; j++)
                psum[i][j] = A[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];

        int ans = 0;
        for (int i = 1; i <= s; i++) {
            for (int j = i; j <= s; j++) {
                for (int k = 1; k <= s; k++) {
                    for (int l = k; l <= s; l++) {
                        int sum = psum[j][l] - psum[i - 1][l] - psum[j][k - 1] + psum[i - 1][k - 1];
                        if (!sum) ans = max(ans, (j - i + 1) * (l - k + 1));
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
}