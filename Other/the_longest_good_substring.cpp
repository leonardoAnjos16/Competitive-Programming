#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k; cin >> k;
    string s; cin >> s;

    int l = 0, cnt = 1;
    pair<int, int> ans = make_pair(1, 1);

    vector<int> last(26, -1);
    last[s[0] - 'a'] = 0;

    for (int r = 1; r < (int) s.size(); r++) {
        if (last[s[r] - 'a'] != -1) {
            last[s[r] - 'a'] = r;
            if (r - l > ans.second - ans.first)
                ans = make_pair(l + 1, r + 1);
        } else if (cnt < k) {
            cnt++;
            last[s[r] - 'a'] = r;

            if (r - l > ans.second - ans.first)
                ans = make_pair(l + 1, r + 1);
        } else {
            int mn = INT_MAX, idx = -1;
            for (int i = 0; i < 26; i++)
                if (last[i] != -1 && last[i] < mn)
                    mn = last[i], idx = i;

            l = mn + 1;
            last[idx] = -1;
            last[s[r] - 'a'] = r;

            if (r - l > ans.second - ans.first)
                ans = make_pair(l + 1, r + 1);
        }
    }

    cout << ans.first << " " << ans.second << "\n";
}