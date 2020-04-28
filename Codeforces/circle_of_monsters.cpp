#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 3e5 + 5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);

        long a[MAX], b[MAX];
        for (int i = 0; i < n; i++)
            scanf("%lld %lld", &a[i], &b[i]);

        long s = 0LL;
        for (int i = 0; i < n; i++)
            s += max(0LL, a[i] - b[(i + n - 1) % n]);

        long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long bullets = a[i] + s - max(0LL, a[i] - b[(i + n - 1) % n]);
            ans = min(ans, bullets);
        }

        printf("%lld\n", ans);
    }
}