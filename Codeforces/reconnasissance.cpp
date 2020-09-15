#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int n, d; scanf("%d %d", &n, &d);

    int h[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);

    sort(h, h + n);

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int idx = upper_bound(h, h + n, h[i] + d) - h;
        ans += (idx - i - 1) * 2;
    }

    printf("%d\n", ans);
}