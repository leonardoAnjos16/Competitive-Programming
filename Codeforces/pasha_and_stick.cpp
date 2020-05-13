#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    int ans = n & 1 ? 0 : ceil(n / 4.0) - 1;
    printf("%d\n", ans);
}