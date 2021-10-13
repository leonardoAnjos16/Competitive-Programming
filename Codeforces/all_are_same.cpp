#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = gcd(ans, a[i] - mn);

        if (!ans) ans = -1;
        cout << ans << "\n";
    }
}