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

        sort(a.begin() + 1, a.end());

        llong ans = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] <= ans) continue;
            ans += (a[i] - ans + 1) / 2;
        }

        cout << ans << "\n";
    }
}