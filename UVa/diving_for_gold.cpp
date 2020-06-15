#include <bits/stdc++.h>

using namespace std;

#define treasure pair<int, int>
#define depth first
#define value second

const int MAX_T = 1e3 + 5;
const int MAX_N = 40;

int main() {
    int t, w;
    bool first = true;

    while (scanf("%d %d", &t, &w) != EOF) {
        if (!first) printf("\n");
        else first = false;

        int n; scanf("%d", &n);
        w *= 3;

        int d[MAX_N], v[MAX_N];
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &d[i], &v[i]);

        int dp[MAX_N][MAX_T] = {0};
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                if (!i || !j) continue;

                dp[i][j] = dp[i - 1][j];
                if (w * d[i] <= j) dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w * d[i]]);
            }
        }

        stack<treasure> ans;
        int i = n, j = t;

        while (i && j) {
            if (dp[i][j] == dp[i - 1][j]) i--;
            else {
                ans.push({d[i], v[i]});
                j -= w * d[i]; i--;
            }
        }

        printf("%d\n", dp[n][t]);
        printf("%d\n", (int) ans.size());

        while (!ans.empty()) {
            printf("%d %d\n", ans.top().depth, ans.top().value);
            ans.pop();
        }
    }
}