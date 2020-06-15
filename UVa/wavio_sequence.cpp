#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int A[MAX];
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        int LIS[MAX], aux[MAX], len = 0;
        for (int i = 0; i < N; i++) {
            int idx = lower_bound(aux, aux + len, A[i]) - aux;
            aux[idx] = A[i]; LIS[i] = idx + 1;
            if (idx >= len) len++;
        }

        int LDS[MAX], ans = 1; len = 0;
        for (int i = N - 1; i >= 0; i--) {
            int idx = lower_bound(aux, aux + len, A[i]) - aux;
            aux[idx] = A[i]; LDS[i] = idx + 1;
            if (idx >= len) len++;

            ans = max(ans, 2 * min(LIS[i], LDS[i]) - 1);
        }

        printf("%d\n", ans);
    }
}