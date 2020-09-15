#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int A[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        sort(A, A + n);

        bool possible = true;
        for (int i = 1; i < n && possible; i++)
            if (A[i] - A[i - 1] > 1) possible = false;

        printf("%s\n", possible ? "YES" : "NO");
    }
}