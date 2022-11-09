#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        int cnt[2] = {0};
        llong sums[2] = {0LL};

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[!!(a & 1)]++;
            sums[!!(a & 1)] += a;
        }

        while (q--) {
            int type, x;
            cin >> type >> x;

            sums[type] += 1LL * cnt[type] * x;
            if (x & 1) {
                cnt[1 - type] = n;
                sums[1 - type] += sums[type];
                cnt[type] = sums[type] = 0;
            }

            llong ans = sums[0] + sums[1];
            cout << ans << "\n";
        }
    }
}