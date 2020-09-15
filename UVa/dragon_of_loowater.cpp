#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e4 + 5;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), n | m) {
        int d[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &d[i]);

        int h[MAX];
        for (int i = 0; i < m; i++)
            scanf("%d", &h[i]);

        sort(d, d + n);
        sort(h, h + m);

        long ans = 0LL;
        int idx = 0;

        bool possible = true;
        for (int i = 0; i < n && possible; i++) {
            while (idx < m && h[idx] < d[i]) idx++;
            if (idx >= m) possible = false;
            else ans += h[idx++];
        }

        if (!possible) printf("Loowater is doomed!\n");
        else printf("%lld\n", ans);
    }
}