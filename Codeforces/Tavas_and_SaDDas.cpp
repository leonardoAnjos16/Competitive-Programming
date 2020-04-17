#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    int idx = 0, ans = 0;
    while (n) {
        if (n % 10 == 4) ans += (1 << idx);
        else ans += (1 << (idx + 1));

        idx++;
        n /= 10;
    }

    printf("%d\n", ans);
}