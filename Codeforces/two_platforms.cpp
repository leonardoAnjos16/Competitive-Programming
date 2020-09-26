#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int n, k, x[MAX];
int memo[MAX], cnt[MAX];

int points(int i) {
    if (i >= n) return 0;

    int &ans = memo[i];
    if (~ans) return ans;

    return ans = max(cnt[i], points(i + 1));
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &x[i]);

        for (int i = 0; i < n; i++)
            scanf("%*d");

        memset(memo, -1, sizeof memo);
        sort(x, x + n);

        for (int i = 0; i < n; i++)
            cnt[i] = upper_bound(x + i, x + n, x[i] + k) - x - i;

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int end = upper_bound(x + i, x + n, x[i] + k) - x;
            ans = max(ans, cnt[i] + points(end));
        }

        printf("%d\n", ans);
    }
}