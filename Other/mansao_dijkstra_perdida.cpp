#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cout << "0 0\n";
        cout.flush();

        long d1; cin >> d1;
        if (!d1) continue;

        cout << "1 0\n";
        cout.flush();

        long d2; cin >> d2;
        if (!d2) continue;

        long x = (d1 - d2 + 1LL);
        assert(!(x & 1LL));
        x >>= 1LL;

        long y = sqrtl(d1 - x * x);
        cout << x << " " << y << "\n";
        cout.flush();

        long d; cin >> d;
        if (!d) continue;

        cout << x << " " << -y << "\n";
        cout.flush();

        cin >> d;
        assert(!d);
    }
}