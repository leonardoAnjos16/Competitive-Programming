#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;

        int kuse = min(m / k, ak);
        m -= k * kuse;
        ak -= kuse;

        if (a1 >= m) cout << "0\n";
        else {
            int need = m - a1;
            int ans = need / k + need % k;

            if (k - (need % k) <= a1)
                ans = min(ans, need / k + 1);

            cout << ans << "\n";
        }
    }
}