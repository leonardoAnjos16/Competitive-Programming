#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 1;
        for (int i = 1; i < n && ans; i++) {
            if (a[i - 1] % a[i]) ans = 0;
            else {
                int div = a[i - 1] / a[i];

                vector<int> factors;
                for (int i = 2; i * i <= div; i++) {
                    if (!(div % i)) factors.push_back(i);
                    while (!(div % i)) div /= i;
                }

                if (div > 1) factors.push_back(div);

                int size = factors.size(), cnt = 0;
                for (int j = 0; j < (1 << size); j++) {
                    int mult = 1;
                    for (int k = 0; k < size; k++)
                        if (j & (1 << k)) mult *= factors[k];

                    if (__builtin_popcount(j) & 1) cnt -= (m / a[i]) / mult;
                    else cnt += (m / a[i]) / mult;
                }

                ans = (1LL * ans * cnt) % MOD;
            }
        }

        cout << ans << "\n";
    }
}