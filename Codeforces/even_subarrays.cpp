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

        vector<int> cnt(2 * n, 0);
        cnt[0] = 1;

        int x = 0;
        llong odd = 0LL;

        for (int i = 0; i < n; i++) {
            x ^= a[i];
            for (int j = 0; j * j < 2 * n; j++)
                if ((x ^ (j * j)) < 2 * n)
                    odd += cnt[x ^ (j * j)];

            cnt[x]++;
        }

        llong ans = n * (n + 1LL) / 2LL - odd;
        cout << ans << "\n";
    }
}