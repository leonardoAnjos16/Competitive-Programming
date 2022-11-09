#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        bool found = false;
        llong prod = 1LL * a * b;

        for (int x = a + 1; x <= c && !found; x++) {
            llong g = gcd(1LL * x, prod);
            llong rem = prod / g;

            // rem * y' > b
            // y' > b / rem
            llong mn = b / rem + 1LL;

            // rem * y' <= d
            // y' <= d / rem
            llong mx = d / rem;

            if (mn <= mx) {
                found = true;
                int y = rem * mn;
                assert(y > b && y <= d);
                cout << x << " " << y << "\n";
            }
        }

        if (!found) cout << "-1 -1\n";
    }
}