#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long mn = 0LL, mx = a[0], sum = a[0];
    for (int i = 1; i < n; i++) {
        if (i & 1) {
            sum -= a[i];
            mn = max(mn, sum);
        } else {
            sum += a[i];
            mx = min(mx, sum);
        }
    }

    long ans = max(mx - mn + 1LL, 0LL);
    cout << ans << "\n";
}