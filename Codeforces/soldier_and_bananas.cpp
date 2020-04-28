#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n, w; scanf("%d %d %d", &k, &n, &w);
    int ans = max(0, (k * w * (w + 1) / 2) - n);
    printf("%d\n", ans);
}