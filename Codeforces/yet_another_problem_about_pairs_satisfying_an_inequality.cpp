#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        llong ans = 0LL;
        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int a; cin >> a;

            if (a && a < i) ans += cnt[a - 1];

            cnt[i] = cnt[i - 1];
            cnt[i] += a < i;
        }

        cout << ans << "\n";
    }
}