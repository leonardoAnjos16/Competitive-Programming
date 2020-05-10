#include <bits/stdc++.h>

using namespace std;

const int MAX = 8e4 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int cnt[MAX] = {0};
        for (int i = 0; i < n; i++)
            cnt[a[i]]++;

        int ans = 0;
        for (int i = 0; i < n - 1 && ans < n; i++) {
            int sum = a[i], idx = i;
            while (ans < n && idx + 1 < n && sum + a[idx + 1] <= n) {
                sum += a[++idx];
                ans += cnt[sum];
                cnt[sum] = 0;
            }
        }

        printf("%d\n", ans);
    }
}