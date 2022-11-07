#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int mx = INT_MIN;
    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        mx = max(mx, x[i]);
    }

    llong l = mx, r = 1e18, ans = -1LL;
    while (l <= r) {
        llong mid = (l + r) / 2LL;

        int cnt = 1;
        llong sum = 0LL;

        for (int i = 0; i < n; i++) {
            if (sum + x[i] <= mid) sum += x[i];
            else cnt++, sum = x[i];
        }

        if (cnt > k) l = mid + 1LL;
        else r = mid - 1LL, ans = mid;
    }

    cout << ans << "\n";
}