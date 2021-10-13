#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> x(k);
        for (int i = 0; i < k; i++)
            cin >> x[i];

        sort(x.rbegin(), x.rend());

        int l = 0, r = k, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            long need = 0LL;
            for (int i = 0; i < mid; i++)
                need += n - x[i];

            if (need >= n) r = mid - 1;
            else l = mid + 1, ans = mid;
        }

        cout << ans << "\n";
    }
}