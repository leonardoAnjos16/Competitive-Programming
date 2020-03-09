#include <bits/stdc++.h>

using namespace std;

#define lb lower_bound

const int MAX = 5e2 + 5;

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M), N || M) {
        int props[MAX][MAX];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &props[i][j]);

        int Q; scanf("%d", &Q);
        while (Q--) {
            int L, U; scanf("%d %d", &L, &U);

            int max_size = 0;
            for (int i = 0; i < N; i++) {
                int index = lb(props[i], props[i] + M, L) - props[i];
                for (int j = max_size; (i + j) < N && (index + j) < M && props[i + j][index + j] <= U; j++)
                    max_size = max(max_size, j + 1);
            }

            printf("%d\n", max_size);
        }

        printf("-\n");
    }
}