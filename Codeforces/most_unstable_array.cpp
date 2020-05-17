#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);

        int ans = n > 2 ? m << 1 : (n == 2 ? m : 0);
        printf("%d\n", ans);
    }
}