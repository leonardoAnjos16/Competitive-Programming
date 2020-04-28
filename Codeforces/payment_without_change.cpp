#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int a, b, n, S;
        scanf("%d %d %d %d", &a, &b, &n, &S);

        int x = min(a, S / n);
        int y = S - (n * x);

        printf("%s\n", y <= b ? "YES" : "NO");
    }
}