#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

    vector<int> dp(1 << m, 0);
    for (int i = 0; i < n; i++)
        dp[a[i]] = a[i];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < (1 << m); j++)
            if ((j & (1 << i)) && !dp[j])
                dp[j] = dp[j ^ (1 << i)];

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";

        int aux = (1 << m) - 1;
        for (int j = 0; j < m; j++)
            if (a[i] & (1 << j))
                aux ^= 1 << j;

        if (!dp[aux]) cout << "-1";
        else cout << dp[aux];
    }

    cout << "\n";
}