#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> primes;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;

            for (int j = 2; j * j <= a; j++)
                while (!(a % j)) {
                    primes.push_back(j);
                    a /= j;
                }

            if (a > 1) primes.push_back(a);
        }

        sort(primes.begin(), primes.end());

        int ans = 0, rem = 0, cnt = 1;
        for (int i = 1; i < (int) primes.size(); i++) {
            if (primes[i] == primes[i - 1]) cnt++;
            else ans += cnt / 2, rem += cnt % 2, cnt = 1;
        }

        ans += cnt / 2;
        rem += cnt % 2;

        ans += rem / 3;
        rem %= 3;

        if (rem && !ans) cout << "0\n";
        else cout << ans << "\n";
    }
}