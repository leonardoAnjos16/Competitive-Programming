#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int cnt = 0, last = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (last == -1 || !!(a & 1) == last) cnt++;
            else ans += cnt - 1, cnt = 1;
            last = !!(a & 1);
        }

        ans += cnt - 1;
        cout << ans << "\n";
    }
}