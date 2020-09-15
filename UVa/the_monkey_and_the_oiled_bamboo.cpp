#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int n; scanf("%d", &n);

        int r[MAX] = {0};
        for (int j = 1; j <= n; j++)
            scanf("%d", &r[j]);

        int lo = 0, hi = r[n], ans;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int k = mid, idx = 0;
            while (++idx <= n && k >= r[idx] - r[idx - 1])
                if (k == r[idx] - r[idx - 1]) k--;

            if (idx <= n) lo = mid + 1;
            else ans = mid, hi = mid - 1;
        }

        printf("Case %d: %d\n", i, ans);
    }
}