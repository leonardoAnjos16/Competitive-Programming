#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        llong k; cin >> k;

        llong p = 1LL;
        while (p * 9LL <= k)
            p *= 9LL;

        llong ans = 0LL;
        while (p) {
            int d = k / p;
            assert(d <= 8);
            if (d >= 4) d++;

            ans *= 10LL;
            ans += d;

            k %= p;
            p /= 9LL;
        }

        cout << ans << "\n";
    }
}