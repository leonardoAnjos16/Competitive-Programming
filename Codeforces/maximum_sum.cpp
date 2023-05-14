#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        vector<llong> ps(n + 1, 0LL);
        for (int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + a[i - 1];

        llong ans = 0LL;
        for (int i = 0; i <= k; i++) {
            int r = n - i;
            int l = 2 * (k - i);
            ans = max(ans, ps[r] - ps[l]);
        }

        cout << ans << "\n";
    }
}