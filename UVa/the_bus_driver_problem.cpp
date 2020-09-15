#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n, d, r;
    while (scanf("%d %d %d", &n, &d, &r), n | d | r) {
        int m[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &m[i]);

        int e[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &e[i]);

        sort(m, m + n);
        sort(e, e + n, greater<int>());

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += max(0, r * (m[i] + e[i] - d));

        printf("%d\n", ans);
    }
}