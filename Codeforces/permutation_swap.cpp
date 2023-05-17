#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int p; cin >> p;
            ans = gcd(ans, abs(p - i - 1));
        }

        cout << ans << "\n";
    }
}