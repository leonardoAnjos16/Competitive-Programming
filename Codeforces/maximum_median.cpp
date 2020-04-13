#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;

int main() {
    int n, k; scanf("%d %d", &n, &k);

    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);

    long l = a[n / 2], r = l + k, ans;
    while (l <= r) {
        long mid = (l + r) / 2;

        long sum = 0;
        for (int i = n / 2; i < n; i++)
            sum += max(0LL, mid - a[i]);

        if (sum > k) r = mid - 1;
        else ans = mid, l = mid + 1;
    }

    printf("%lld\n", ans);
}