#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        int ans = 1;
        for (int i = 0; i < n; i++) {
            int greater = a.end() - upper_bound(a.begin(), a.end(), b[i]) - i;
            if (greater <= 0) ans = 0;
            else ans = (1LL * ans * greater) % MOD;
        }

        cout << ans << "\n";
    }
}