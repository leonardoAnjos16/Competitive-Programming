#include <bits/stdc++.h>

using namespace std;

int f(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return i;

    return n;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);

        n += f(n) + (k - 1) * 2;
        printf("%d\n", n);
    }
}