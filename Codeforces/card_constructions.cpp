#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int ans = 0;
        while (n > 1) {
            int l = 0, r = n, h;
            while (l <= r) {
                int mid = (l + r) / 2;

                long cards = 3LL * mid * (mid + 1) / 2LL - mid;
                if (cards > n) r = mid - 1;
                else h = mid, l = mid + 1;
            }

            n -= 3LL * h * (h + 1) / 2LL - h; ans++;
        }

        printf("%d\n", ans);
    }
}