#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int y, x;
        cin >> y >> x;

        int l = max(y, x);
        long long int ans = (l - 1LL) * (l - 1LL);
        
        if (l & 1) {
            ans += x;
            if (x == l)
                ans += l - y;
        } else {
            ans += y;
            if (y == l)
                ans += l - x;
        }

        cout << ans << "\n";
    }
}