#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, x; scanf("%d %d", &n, &x);

        int A[MAX], change = 0, ans = 0;
        bool equal = false;

        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            change += x - A[i];

            if (A[i] != x) ans = 1;
            if (A[i] == x) equal = true;
        }

        if (change && !equal) ans++;
        printf("%d\n", ans);
    }
}