#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        int n; cin >> n;

        vector<string> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        int l = 0;
        bool possible = true;
        vector<pair<int, int>> ans;

        while (l < (int) t.size() && possible) {
            bool found = false;
            int r = (int) t.size() - 1;

            while (l <= r && !found) {
                for (int i = 0; i < n && !found; i++) {
                    if ((int) s[i].size() > r + 1 || (int) s[i].size() < r - l + 1) continue;
                    if (t.substr(r - (int) s[i].size() + 1, (int) s[i].size()) == s[i]) {
                        found = true;
                        ans.emplace_back(i + 1, r - (int) s[i].size() + 2);
                    }
                }

                if (!found) r--;
            }

            if (l <= r) l = r + 1;
            else possible = false;
        }

        if (!possible) cout << "-1\n";
        else {
            int cnt = ans.size();
            cout << cnt << "\n";

            for (auto [w, p]: ans)
                cout << w << " " << p << "\n";
        }
    }
}