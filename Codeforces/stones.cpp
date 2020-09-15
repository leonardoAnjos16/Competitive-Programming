#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);

        int ans = min(b, c / 2);
        b -= ans;

        ans += min(a, b / 2);
        ans *= 3;

        printf("%d\n", ans);
    }
}