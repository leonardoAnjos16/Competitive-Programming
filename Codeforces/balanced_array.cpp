#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int half = n >> 1;
        if (half & 1) printf("NO\n");
        else {
            printf("YES\n");

            int even_sum = 0;
            for (int i = 1; i <= half; i++) {
                printf("%d ", i << 1);
                even_sum += i << 1;
            }

            int odd_sum = 0;
            for (int i = 0; i < half - 1; i++) {
                printf("%d ", (i << 1) + 1);
                odd_sum += (i << 1) + 1;
            }

            printf("%d\n", even_sum - odd_sum);
        }
    }
}