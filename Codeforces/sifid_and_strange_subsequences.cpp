#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int zeroes = 0;
        vector<int> sub, pos;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (!a) zeroes++;
            if (a <= 0) sub.push_back(a);
            else pos.push_back(a);
        }

        sort(sub.begin(), sub.end());
        sort(pos.begin(), pos.end());

        int mn_diff = INT_MAX;
        for (int i = 1; i < (int) sub.size(); i++)
            mn_diff = min(mn_diff, abs(sub[i] - sub[i - 1]));

        int ans = (int) sub.size();
        if (zeroes < 2 && (int) pos.size() > 0) {
            auto it = upper_bound(pos.begin(), pos.end(), mn_diff);
            if (ans < 2 || it != pos.begin()) ans++;
        }

        cout << ans << "\n";
    }
}