#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e4 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int p[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);

        sort(p, p + n, greater<int>());

        int ans = 0;
        for (int i = 2; i < n; i += 3)
            ans += p[i];

        printf("%d\n", ans);
    }
}