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
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int mn = min_element(a.begin(), a.end()) - a.begin();
        int mx = max_element(a.begin(), a.end()) - a.begin();

        if (mn > mx) swap(mn, mx);

        int ans = min({ mx + 1, n - mn, mn + 1 + n - mx });
        cout << ans << "\n";
    }
}