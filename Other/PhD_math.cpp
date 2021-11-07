#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        unsigned long a, b; int n, p;
        cin >> a >> b >> n >> p;

        string s = ".";
        for (int i = 0; i < n; i++) {
            a *= 10ULL;
            s += '0' + (a / b);
            a %= b;
        }

        long ans = 0LL;
        vector<long> dp(p, 0LL);

        for (int i = 1; i <= n; i++) {
            vector<long> curr(p, 0LL);
            curr[(s[i] - '0') % p]++;

            for (int j = 0; j < p; j++)
                curr[(10 * j + s[i] - '0') % p] += dp[j];

            dp = curr;
            ans += dp[0];
        }

        cout << ans << "\n";
    }
}