#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;

int main() {
    int C, S, num_set = 1;
    while (scanf("%d %d", &C, &S) != EOF) {
        int A[MAX], sum = 0;
        for (int i = 0; i < S; i++) {
            scanf("%d",&A[i]);
            sum += A[i];
        }

        while (S < 2 * C) A[S++] = 0;
        sort(A, A + S);

        printf("Set #%d\n", num_set++);

        double avg = sum / (C + .0), imb = 0;
        for (int i = 0; i < C; i++) {
            printf("%2d:", i);
            if (A[i]) printf(" %d", A[i]);
            if (A[S - i - 1]) printf(" %d", A[S - i - 1]);
            printf("\n");

            imb += fabs(A[i] + A[S - i - 1] - avg);
        }

        printf("IMBALANCE = %.5lf\n\n", imb);
    }
}