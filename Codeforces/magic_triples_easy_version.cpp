#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        int cnt[MAX] = {0};

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        llong ans = 0LL;
        for (int i = 0; i < n; i++) {
            for (int j = 2; j * j <= a[i]; j++)
                if (!(a[i] % j)) {
                    if (1LL * a[i] * j < MAX)
                        ans += 1LL * cnt[a[i] / j] * cnt[a[i] * j];

                    int d = a[i] / j;
                    if (j != d && 1LL * a[i] * d < MAX)
                        ans += 1LL * cnt[j] * cnt[a[i] * d];
                }

            if (cnt[a[i]] >= 3) ans += (cnt[a[i]] - 1LL) * (cnt[a[i]] - 2LL);
            if (a[i] > 1 && 1LL * a[i] * a[i] < MAX) ans += 1LL * cnt[1] * cnt[a[i] * a[i]];
        }

        cout << ans << "\n";
    }
}