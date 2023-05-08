#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<bool> taken(m, false);
        int left = 0, right = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == -1) left++;
            else if (x == -2) right++;
            else {
                if (!taken[x - 1]) cnt++;
                taken[x - 1] = true;
            }
        }

        int ans = cnt + min(m - cnt, max(left, right)), seen = 0;
        for (int i = 0; i < m; i++)
            if (taken[i]) {
                ans = max(ans, cnt + min(i - seen, left) + min(m - i - cnt + seen, right));
                seen++;
            }

        cout << ans << "\n";
    }
}