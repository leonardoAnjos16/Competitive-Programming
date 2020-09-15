#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;

long sum_first(int n) {
    return ((long) n) * (n + 1) / 2;
}

int main() {
    int n, d; scanf("%d %d", &n, &d);

    int x[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    long ans = 0;
    for (int i = 0; i < n - 2; i++) {
        int idx = upper_bound(x, x + n, x[i] + d) - x - 1;
        ans += sum_first(idx - i - 1);
    }

    printf("%lld\n", ans);
}