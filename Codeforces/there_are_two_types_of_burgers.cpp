#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int b, p, f; scanf("%d %d %d", &b, &p, &f);
        int h, c; scanf("%d %d", &h, &c);

        int ans = 0;
        if (h > c) {
            int aux = min(p, b / 2);
            ans = h * aux;
            b -= aux << 1;
            ans += c * min(f, b / 2);
        } else {
            int aux = min(f, b / 2);
            ans = c * aux;
            b -= aux << 1;
            ans += h * min(p, b / 2);
        }

        printf("%d\n", ans);
    }
}