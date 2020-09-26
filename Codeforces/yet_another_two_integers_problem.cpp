#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b; scanf("%d %d", &a, &b);
        int diff = abs(b - a);

        int ans = ceil(diff / 10.0);
        printf("%d\n", ans);
    }
}