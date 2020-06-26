#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);
        char s[MAX]; scanf("%s", s);

        int pos[MAX] = {-1}, cnt = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') pos[++cnt] = i;

        pos[++cnt] = n;

        int ans = 0;
        for (int i = 1; i <= cnt; i++) {
            int zeros = pos[i] - pos[i - 1] - 2 * k - 1;
            if (i == 1) zeros += k;
            if (i == cnt) zeros += k;

            if (zeros > 0) ans += 1 + (zeros - 1) / (k + 1);
        }

        printf("%d\n", ans);
    }
}