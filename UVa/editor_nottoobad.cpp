#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);

        char A[MAX][MAX];
        for (int i = 0; i < N; i++)
            scanf("%s", A[i]);

        int ans = strlen(A[0]);
        for (int i = 0; i < N - 1; i++) {
            int idx, cnt = -1;
            for (int j = i + 1; j < N; j++) {
                int aux = 0, lim = min(strlen(A[i]), strlen(A[j]));
                while (aux < lim && A[i][aux] == A[j][aux]) aux++;
                if (aux > cnt) idx = j, cnt = aux;
            }

            ans += strlen(A[idx]) - cnt;
            swap(A[i + 1], A[idx]);
        }

        printf("%d\n", ans);
        for (int i = 0; i < N; i++)
            printf("%s\n", A[i]);
    }
}