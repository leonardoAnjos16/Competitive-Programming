#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a[MAX], min_a = INT_MAX;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            min_a = min(min_a, a[i]);
        }

        int b[MAX], min_b = INT_MAX;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            min_b = min(min_b, b[i]);
        }

        long long int ans = 0LL;
        for (int i = 0; i < n; i++)
            ans += min(a[i] - min_a, b[i] - min_b) + abs((a[i] - min_a) - (b[i] - min_b));

        printf("%lld\n", ans);
    }
}