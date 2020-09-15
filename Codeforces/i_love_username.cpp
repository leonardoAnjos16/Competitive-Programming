#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    int p; scanf("%d", &p);
    int min_p = p, max_p = p;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d", &p);

        ans += p < min_p || p > max_p;
        min_p = min(min_p, p);
        max_p = max(max_p, p);
    }

    printf("%d\n", ans);
}