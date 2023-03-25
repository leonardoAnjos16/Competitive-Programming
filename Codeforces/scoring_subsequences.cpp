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

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";

            int l = 0, r = i, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (a[i - mid] < mid + 1) r = mid - 1;
                else l = mid + 1, idx = i - mid;
            }

            assert(idx != -1);

            int ans = i - idx + 1;
            cout << ans;
        }

        cout << "\n";
    }
}