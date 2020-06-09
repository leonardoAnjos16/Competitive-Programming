#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);

        int M[MAX][MAX], num = 1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                M[i][j] = num++;

        if (!(N & 1))
            for (int i = 1; i < N; i += 2)
                for (int j = 1; j < N; j += 2)
                    swap(M[i][j - 1], M[i][j]);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j) printf(" ");
                printf("%d", M[i][j]);
            }

            printf("\n");
        }
    }
}