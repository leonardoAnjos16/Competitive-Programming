#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int n; scanf("%d", &n);

        int A[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        for (int i = 0; i < n - 1;) {
            int pos = i;
            for (int j = i + 1; j < n; j++)
                if (A[j] < A[pos]) pos = j;

            int min = A[pos];
            for (int j = pos; j > i; j--)
                A[j] = A[j - 1];

            A[i] = min;
            
            if (i == pos) i++;
            else i = pos;
        }

        for (int i = 0; i < n; i++)
            printf("%d ", A[i]);

        printf("\n");
    }
}