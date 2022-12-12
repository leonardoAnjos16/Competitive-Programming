#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int cnt = 0;
        while (n >= 10) {
            cnt++;
            n /= 10;
        }

        int ans = n + 9 * cnt;
        cout << ans << "\n";
    }
}