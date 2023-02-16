#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n + 5);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> b(n + 5);
        for (int i = 1; i <= n; i++)
            cin >> b[i];

        vector<llong> ps(n + 5, 0LL);
        for (int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + b[i];

        vector<int> cnt(n + 5, 0);
        vector<llong> sum(n + 5, 0LL);

        for (int i = 1; i <= n; i++) {
            int l = i, r = n, idx = n + 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (ps[mid] - ps[i - 1] <= a[i]) l = mid + 1;
                else r = mid - 1, idx = mid;
            }

            if (idx == i) sum[i] += a[i];
            else {
                cnt[i]++;
                cnt[idx]--;
                sum[idx] += a[i] - (ps[idx - 1] - ps[i - 1]);
            }
        }

        for (int i = 1; i <= n; i++)
            cnt[i] += cnt[i - 1];

        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << " ";
            llong ans = 1LL * cnt[i] * b[i] + sum[i];
            cout << ans;
        }

        cout << "\n";
    }
}