#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, x; scanf("%d %d", &n, &x);

        int a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        sort(a, a + n);

        int idx = upper_bound(a, a + n, x) - a;
        long sum = 0LL;

        for (int i = idx; i < n; i++)
            sum += a[i] - x;

        while (idx && sum >= 0) {
            long need = x - a[--idx];
            a[idx] += min(need, sum);
            sum -= need;
        }

        int ans = n - idx;
        if (a[idx] < x) ans--;

        printf("%d\n", ans);
    }
}