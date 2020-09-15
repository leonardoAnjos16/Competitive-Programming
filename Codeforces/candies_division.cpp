#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);

        int ans = n - max(0, (n % k) - (k / 2));
        printf("%d\n", ans);
    }
}