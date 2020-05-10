#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int A[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        int moves = 0, a = 0, b = 0;
        int l = 0, r = n - 1, last = 0;

        while (l <= r) {
            int eaten = 0;
            if (!(moves & 1)) {
                while (l <= r && eaten + A[l] <= last) eaten += A[l], a += A[l++];
                if (l <= r) eaten += A[l], a += A[l++];
            } else {
                while (r >= l && eaten + A[r] <= last) eaten += A[r], b += A[r--];
                if (r >= l) eaten += A[r], b += A[r--];
            }

            last = eaten;
            moves++;
        }

        printf("%d %d %d\n", moves, a, b);
    }
}