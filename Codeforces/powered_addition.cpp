#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int T = 0;
        for (int i = 1; i < n; i++) {
            int diff = max(0, a[i - 1] - a[i]);
            a[i] += diff;

            int exp = 0;
            while (diff) exp++, diff = diff >> 1;
            T = max(T, exp);
        }

        printf("%d\n", T);
    }
}