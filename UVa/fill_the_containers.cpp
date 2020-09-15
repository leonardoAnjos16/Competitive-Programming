#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int c[MAX], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
            l = max(l, c[i]);
            r += c[i];
        }

        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            int idx = 0, max_s = INT_MIN, rem = m;
            while (idx < n && rem) {
                int s = c[idx];
                while (idx + 1 < n && s + c[idx + 1] <= mid) s += c[++idx];

                max_s = max(max_s, s);
                idx++; rem--;
            }

            if (idx < n) l = mid + 1;
            else ans = max_s, r = mid - 1;
        }

        printf("%d\n", ans);
    }
}