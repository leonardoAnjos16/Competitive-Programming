#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n; scanf("%d", &n);

    int h[MAX], a, cnt[MAX] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &h[i], &a);
        cnt[a]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += cnt[h[i]];

    printf("%d\n", ans);
}