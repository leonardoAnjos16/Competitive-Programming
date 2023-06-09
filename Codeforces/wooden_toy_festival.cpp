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

        sort(a.begin(), a.end());

        int l = 0, r = 1e9 + 5, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            int idx = 0, carvers = 0;
            while (idx < n) {
                int end = idx;
                bool done = false;

                while (end + 1 < n && !done) {
                    int median = a[idx] + (a[end + 1] - a[idx]) / 2;
                    if (max(median - a[idx], a[end + 1] - median) > mid) done = true;
                    else end++;
                }

                carvers++;
                idx = end + 1;
            }

            if (carvers > 3) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        cout << ans << "\n";
    }
}