#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, int> cnt;

        int sum = 0;
        long long int ans = 0LL;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;

            if (!sum) ans++;
            ans += cnt[sum]++;
        }

        cout << ans << "\n";
    }
}