#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong sum(int r) {
    return r * (r + 1LL) / 2LL;
}

llong sum(int l, int r) {
    return sum(r - l + 1) + (r - l + 1LL) * (l - 1LL);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    llong total = 0LL;
    for (int i = 0; i < n; i++)
        total += a[i];

    vector<int> mn(n);
    mn[0] = a[0];

    for (int i = 1; i < n; i++)
        mn[i] = min(mn[i - 1], a[i] - i);

    while (q--) {
        int k; cin >> k;

        if (n == 1) {
            int ans = a[0];
            if (k & 1) ans += (k + 1) / 2;
            else ans -= k / 2;

            cout << ans << "\n";
        } else {
            llong l = 1LL, r = 2e9 + 5, ans = -1LL;
            while (l <= r) {
                llong mid = (l + r) / 2LL;

                int idx = lower_bound(a.begin(), a.end(), mid) - a.begin();
                bool possible = !idx || mn[idx - 1] + k >= mid;

                int last = k - idx, cnt = idx;
                llong freedom = total + sum(k - idx + 1, k) - 1LL * n * mid;

                if (!(last & 1) && freedom < last / 2 && n - cnt < 2) possible = false;
                else if ((last & 1) && cnt == n) possible = false;

                if (!possible) r = mid - 1LL;
                else l = mid + 1LL, ans = mid;
            }

            cout << ans;
        }

        if (q) cout << " ";
    }
}