#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int z; cin >> z;
    while (z--) {
        int n; cin >> n;

        vector<int> a(n);
        int mx = INT_MIN;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        int m = 0;
        while (mx) {
            m++;
            mx >>= 1;
        }

        vector<int> cnt(1 << m, 0);
        for (int i = 0; i < n; i++)
            cnt[a[i]]++;

        vector<long> dp(1 << m);
        for (int i = 0; i < (1 << m); i++)
            dp[i] = cnt[i];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < (1 << m); j++)
                if (j & (1 << i))
                    dp[j] += dp[j ^ (1 << i)];

        long ans = 0LL;
        for (int i = 0; i < (1 << m); i++)
            ans += cnt[i] * dp[i];

        cout << ans << "\n";
    }
}