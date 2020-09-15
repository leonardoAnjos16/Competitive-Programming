#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h; scanf("%d %d", &n, &h);

    int a, ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        ans += a > h ? 2 : 1;
    }

    printf("%d\n", ans);
}