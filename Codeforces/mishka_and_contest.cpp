#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n, k; scanf("%d %d", &n, &k);

    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int idx = 0, ans = 0;
    while (idx < n && a[idx] <= k) idx++, ans++;
    for (int i = n - 1; i > idx && a[i] <= k; i--) ans++;

    printf("%d\n", ans);
}