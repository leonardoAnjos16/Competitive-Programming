#include <bits/stdc++.h>

using namespace std;

int main() {
    int x; scanf("%d", &x);

    int ans = 0;
    while (x) {
        if (x & 1) ans++;
        x = x >> 1;
    }

    printf("%d\n", ans);
}