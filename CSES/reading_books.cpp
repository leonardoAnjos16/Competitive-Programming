#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    llong sum = 0LL;
    int mx = INT_MIN;

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        mx = max(mx, t);
        sum += t;
    }

    llong ans = max(sum, 2LL * mx);
    cout << ans << "\n";
}