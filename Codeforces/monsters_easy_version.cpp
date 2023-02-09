#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        llong sum = 0LL;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end());

        int nxt = 1;
        llong spells = 0LL, ans = sum;

        for (int i = 0; i < n; i++) {
            sum -= a[i];
            spells += max(a[i] - nxt, 0);
            ans = min(ans, spells + sum);
            if (a[i] >= nxt) nxt++;
        }

        cout << ans << "\n";
    }
}