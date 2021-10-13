#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string n; cin >> n;
        int sz = n.size();

        int ans = INT_MAX;
        for (int i = 0; i < 100; i += 25) {
            int first = i / 10;
            int last = i % 10;

            int r = sz - 1;
            while (r >= 0 && n[r] != '0' + last) r--;

            int l = r - 1;
            while (l >= 0 && n[l] != '0' + first) l--;

            int cnt = INT_MAX;
            if (l >= 0 && r >= 0)
                cnt = sz - r + r - l - 2;

            ans = min(ans, cnt);
        }

        cout << ans << "\n";
    }
}