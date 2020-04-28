#include <bits/stdc++.h>

using namespace std;

const int MAX = 4e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);

        int a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int cnt[MAX] = {0};
        map<int, int> sums;

        for (int i = 0; i < (n >> 1); i++) {
            sums[a[i] + a[n - i - 1]]++;
            cnt[min(a[i], a[n - i - 1]) + 1]++;
            cnt[max(a[i], a[n - i - 1]) + k + 1]--;
        }

        int pref[MAX] = {0};
        for (int i = 1; i <= (k << 1); i++)
            pref[i] = pref[i - 1] + cnt[i];

        int ans = INT_MAX;
        for (int i = 2; i <= (k << 1); i++) {
            int changes = pref[i] - sums[i];
            changes += ((n >> 1) - (changes + sums[i])) << 1;
            ans = min(ans, changes);
        }

        printf("%d\n", ans);
    }
}