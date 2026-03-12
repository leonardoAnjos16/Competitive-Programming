#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int g = 0;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }

    if (g > 1) cout << "YES\n0\n";
    else {
        int ans = 0;
        bool odd = a[0] & 1;

        for (int i = 1; i < n; i++) {
            if ((a[i] & 1)) {
                if (i + 1 < n && !odd) odd = true;
                else if (odd) ans++, a[i]++, odd = false;
                else ans += 2, a[i]++;
            } else if (odd) {
                ans += 2;
                odd = false;
            }
        }

        cout << "YES\n" << ans << "\n";
    }
}