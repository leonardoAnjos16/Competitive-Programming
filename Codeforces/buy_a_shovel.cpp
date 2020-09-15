#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, r; scanf("%d %d", &k, &r);

    int ans = 1;
    while ((ans * k) % 10 && ((ans * k) - r) % 10) ans++;

    printf("%d\n", ans);
}