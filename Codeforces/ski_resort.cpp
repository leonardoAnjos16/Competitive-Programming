#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong sum(int x) {
    return x * (x + 1LL) / 2LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int l = 0;
        llong ans = 0LL;

        while (l < n) {
            while (l < n && a[l] > q) l++;

            int r = l;
            while (r + 1 < n && a[r + 1] <= q) r++;

            if (l < n) {
                if (r - l + 1 >= k)
                    ans += sum(r - l - k + 2);

                l = r + 1;
            }
        }

        cout << ans << "\n";
    }
}