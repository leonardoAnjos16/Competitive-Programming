#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a = (n / 2) + 1;
        int ans = n - a;

        printf("%d\n", ans);
    }
}