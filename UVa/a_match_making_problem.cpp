#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

int main() {
    int B, S, case_num = 1;
    while (scanf("%d %d", &B, &S), B | S) {
        int A[MAX];
        for (int i = 0; i < B; i++)
            scanf("%d", &A[i]);

        int a;
        for (int i = 0; i < S; i++)
            scanf("%d", &a);

        sort(A, A + B);

        printf("Case %d: ", case_num++);
        if (B <= S) printf("0\n");
        else printf("%d %d\n", B - S, A[0]);
    }
}