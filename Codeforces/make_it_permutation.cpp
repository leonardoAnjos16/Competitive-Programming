#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, c, d;
        cin >> n >> c >> d;

        int mx = INT_MIN;
        map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
            mx = max(mx, a);
        }

        int ins = 0;
        llong ans = INF;

        for (int i = 1; i <= n; i++) {
            if (!cnt[i]) ins++;

            int del = n - i + ins;
            ans = min(ans, 1LL * c * del + 1LL * d * ins);
        }

        int last = 0, del = ins;
        for (auto [v, _]: cnt) {
            if (v > n) {
                del--;
                ins += v - last - 1;
                ans = min(ans, 1LL * c * del + 1LL * d * ins);
            }

            last = v;
        }

        cout << ans << "\n";
    }
}