#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("collectingofficer.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;

        int ans = n;
        for (int i = 0; i < n; i++) {
            int r = i;
            char nxt = 'A';

            while (r < n && nxt <= 'Z') {
                while (r < n && s[r] != nxt) r++;
                if (r < n) r++, nxt++;
            }

            if (nxt > 'Z') ans = min(ans, r - i);
        }

        cout << ans << "\n";
    }
}