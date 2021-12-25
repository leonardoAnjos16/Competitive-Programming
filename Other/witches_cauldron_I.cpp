#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    long sum = 0LL;
    int mx = INT_MIN;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    long l = mx, r = sum, ans = -1LL;
    while (l <= r) {
        long mid = (l + r) / 2;

        int cnt = 1;
        long curr = 0LL;

        for (int i = 0; i < n; i++) {
            if (curr + a[i] <= mid) curr += a[i];
            else cnt++, curr = a[i];
        }

        if (cnt > k) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    assert(~ans);
    cout << ans << "\n";
}