#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e3 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int A[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        int LIS[MAX], LDS[MAX], ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            LIS[i] = LDS[i] = 1;
            for (int j = n - 1; j > i; j--) {
                if (A[j] > A[i]) LIS[i] = max(LIS[i], LIS[j] + 1);
                if (A[j] < A[i]) LDS[i] = max(LDS[i], LDS[j] + 1);
            }

            ans = max(ans, LIS[i] + LDS[i] - 1);
        }

        printf("%d\n", ans);
    }
}