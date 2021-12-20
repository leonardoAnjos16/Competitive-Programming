#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long g1 = 0LL, g2 = 0LL;
        for (int i = 0; i < n; i++) {
            if (!(i & 1)) g1 = gcd(g1, a[i]);
            else g2 = gcd(g2, a[i]);
        }

        if (g1 == 1LL && g2 == 1LL) cout << "0\n";
        else {
            bool p1 = g1 != 1LL;
            for (int i = 1; i < n && p1; i += 2)
                if (!(a[i] % g1)) p1 = false;

            bool p2 = g2 != 1LL;
            for (int i = 0; i < n && p2; i += 2)
                if (!(a[i] % g2)) p2 = false;

            if (p1) cout << g1 << "\n";
            else if (p2) cout << g2 << "\n";
            else cout << "0\n";
        }
    }
}