#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int n; scanf("%d", &n);

    int A[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    int s = 0, d = 0, l = 0, r = n - 1, cnt = 0;
    while (l <= r) {
        if (cnt++ & 1) {
            if (A[l] > A[r]) d += A[l++];
            else d += A[r--];
        } else {
            if (A[l] > A[r]) s += A[l++];
            else s += A[r--];
        }
    }

    printf("%d %d\n", s, d);
}