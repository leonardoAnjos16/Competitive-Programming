#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        long n; scanf("%lld", &n);

        int ans = 0;
        while (n > 1 && ans >= 0) {
            if (n % 2 == 0) n /= 2, ans++;
            else if (n % 3 == 0) n = 2 * n / 3, ans++;
            else if (n % 5 == 0) n = 4 * n / 5, ans++;
            else ans = -1;
        }

        printf("%d\n", ans);
    }
}