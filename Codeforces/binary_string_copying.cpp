#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        string s; cin >> s;

        vector<int> left(n, 0);
        for (int i = 1; i < n; i++) {
            left[i] = i;
            if (s[i - 1] == '0')
                left[i] = left[i - 1];
        }

        vector<int> right(n, n - 1);
        for (int i = n - 2; i >= 0; i--) {
            right[i] = i;
            if (s[i + 1] == '1')
                right[i] = right[i + 1];
        }

        vector<int> cnt(n, 0);
        for (int i = 1; i < n; i++)
            cnt[i] = cnt[i - 1] + (s[i - 1] == '1' && s[i] == '0');

        bool equal = false;
        vector<pair<int, int>> t;

        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;

            if (cnt[r - 1] == cnt[l - 1]) equal = true;
            else t.emplace_back(left[l - 1], right[r - 1]);
        }

        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());

        int ans = (int) t.size() + equal;
        cout << ans << "\n";
    }
}