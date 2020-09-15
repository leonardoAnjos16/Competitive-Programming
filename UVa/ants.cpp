#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int l, n; scanf("%d %d", &l, &n);

        double p[MAX];
        for (int i = 0; i < n; i++)
            scanf("%lf", &p[i]);

        sort(p, p + n);

        int mn = INT_MIN;
        for (int i = 0; i < n; i++)
            mn = max(mn, (int) min(p[i], l - p[i]));

        if (p[0] > l - p[n - 1]) {
            reverse(p, p + n);
            for (int i = 0; i < n; i++)
                p[i] = l - p[i];
        }

        double diff = 0.0;
        for (int i = 1; i < n; i++) {
            p[i] = (p[i] - diff + p[i - 1]) / 2.0;
            diff += p[i] - p[i - 1];
        }

        int mx = diff + l - p[n - 1];
        printf("%d %d\n", mn, mx);
    }
}