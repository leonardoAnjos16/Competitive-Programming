#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        long ans = 0LL;
        for (int i = n; i > 1; i -= 2)
            ans += 4LL * (i - 1) * (i / 2LL);

        printf("%lld\n", ans);
    }
}