#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a, b, c = 0;
        for (a = 2; a * a < n && !c; a++) if (n % a == 0)
            for (b = a + 1; b * b < n / a && !c; b++)
                if (n % (a * b) == 0) c = n / (a * b);

        if (!c) printf("NO\n");
        else printf("YES\n%d %d %d\n", --a, --b, c);
    }
}