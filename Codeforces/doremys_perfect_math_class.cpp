#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int g = 0, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            g = gcd(g, a);
            mx = max(mx, a);
        }

        int ans = mx / g;
        cout << ans << "\n";
    }
}