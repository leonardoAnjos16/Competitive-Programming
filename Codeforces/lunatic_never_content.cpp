#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0;
        for (int l = 0, r = n - 1; l < r; l++, r--)
            ans = gcd(ans, abs(a[l] - a[r]));

        cout << ans << "\n";
    }
}