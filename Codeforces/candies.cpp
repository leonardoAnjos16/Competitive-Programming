#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int k = 1;
        while (n % ((1 << ++k) - 1));

        int x = n / ((1 << k) - 1);
        printf("%d\n", x);
    }
}