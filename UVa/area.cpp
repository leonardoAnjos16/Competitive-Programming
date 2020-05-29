#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

int main() {
    int T; scanf("%d", &T);
    int case_num = 1;

    while (T--) {
        int N, M, K; scanf("%d %d %d", &N, &M, &K);

        long psum[MAX][MAX] = {0};
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                scanf("%lld", &psum[i][j]);
                psum[i][j] += psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
            }
        }

        int max_area = 0; long min_price = 0LL;
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                for (int k = 1; k <= M; k++) {
                    for (int l = k; l <= M; l++) {
                        int area = (j - i + 1) * (l - k + 1);
                        long price = psum[j][l] - psum[j][k - 1] - psum[i - 1][l] + psum[i - 1][k - 1];

                        if (price <= K) {
                            if (area > max_area) max_area = area, min_price = price;
                            else if (area == max_area) min_price = min(min_price, price);
                        }
                    }
                }
            }
        }

        printf("Case #%d: %d %lld\n", case_num++, max_area, min_price);
    }
}