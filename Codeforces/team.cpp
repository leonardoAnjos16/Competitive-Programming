#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, aux = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%d", &x);
            aux += x;
        }

        ans += aux > 1;
    }

    printf("%d\n", ans);
}