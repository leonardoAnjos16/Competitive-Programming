#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    while (q--) {
        int k; cin >> k;

        if (n == 1) {
            int ans = a[0];
            if (k & 1) ans += (k + 1) / 2;
            else ans -= k / 2;

            cout << ans;
        } else {
            llong l = 1LL, r = 2e9 + 5, ans = -1LL;
            while (l <= r) {
                llong mid = (l + r) / 2LL;

                bool possible = true;
                int last = k, cnt = 0;
                llong freedom = 0LL;

                for (int i = 0; i < n && a[i] < mid && possible; i++) {
                    if (a[i] + last < mid) possible = false;
                    else freedom += a[i] + last-- - mid, cnt++;
                }

                for (int i = n - 1; i >= 0 && a[i] >= mid; i--)
                    freedom += a[i] - mid;

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