#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int N; scanf("%d", &N);

    int A[MAX];
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    int Q; scanf("%d", &Q);
    while (Q--) {
        int x, y; scanf("%d %d", &x, &y);
        if (A[x - 1] % 2 || (x != y && A[x] == 0)) printf("Odd\n");
        else printf("Even\n");
    }
}