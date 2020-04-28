#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);

        int last_p, last_c;
        scanf("%d %d", &last_p, &last_c);

        bool possible = last_p >= last_c;
        for (int i = 1; i < n; i++) {
            int p, c; scanf("%d %d", &p, &c);
            possible &= p >= c && p >= last_p && c >= last_c && (p - last_p) >= (c - last_c);
            last_p = p; last_c = c;
        }

        printf("%s\n", possible ? "YES" : "NO");
    }
}