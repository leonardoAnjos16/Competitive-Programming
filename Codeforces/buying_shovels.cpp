#include <bits/stdc++.h>

using namespace std;

int max_div(int n, int k) {
    int last = 1;
    for (int i = 2; i * i <= n && i <= k; i++) {
        if (n % i == 0) {
            if (n / i <= k) last = max(last, n / i);
            else last = max(last, i);
        }
    }

    return last;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);

        int ans = n <= k ? 1 : n / max_div(n, k);
        printf("%d\n", ans);
    }
}