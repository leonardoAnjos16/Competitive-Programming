#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

bool all_equal(int A[], int n) {
    int first = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] != first)
            return false;

    return true;
}

int adj_equal(int A[], int n) {
    for (int i = 0; i < n; i++)
        if (A[i] == A[(i + 1) % n])
            return i;

    return -1;
}

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int n; scanf("%d", &n);

        int T[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &T[i]);

        if (all_equal(T, n)) {
            printf("1\n");
            for (int i = 0; i < n; i++) {
                if (i) printf(" ");
                printf("1");
            }

            printf("\n");
        } else {
            int first_pair = adj_equal(T, n);
            if (n % 2 == 0) {
                printf("2\n");

                int color = 0;
                for (int i = 0; i < n; i++) {
                    if (i) printf(" ");
                    printf("%d", color + 1);
                    color = ++color % 2;
                }

                printf("\n");
            } else if (first_pair != -1) {
                printf("2\n");

                int color = 0;
                for (int i = 0; i < n; i++) {
                    if (i) printf(" ");
                    printf("%d", color + 1);

                    if (i != first_pair) color = ++color % 2;
                }

                printf("\n");
            } else {
                printf("3\n");

                int color = 0;
                for (int i = 0; i < n - 1; i++) {
                    printf("%d ", color + 1);
                    color = ++color % 2;
                }

                printf("3\n");
            }
        }
    }
}