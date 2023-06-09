#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int m; cin >> m;

        vector<pair<int, int>> dolls(m);
        for (int i = 0; i < m; i++) {
            int w, h;
            cin >> w >> h;
            dolls[i] = make_pair(w, h);
        }

        sort(dolls.rbegin(), dolls.rend());

        int idx = 0;
        multiset<int> heights;

        while (idx < m) {
            int end = idx + 1;
            while (end < m && dolls[end].first == dolls[idx].first) end++;

            multiset<int> nheights;
            for (int i = idx; i < end; i++) {
                auto it = heights.upper_bound(dolls[i].second);
                if (it != heights.end()) heights.erase(it);
                nheights.insert(dolls[i].second);
            }

            for (int h: nheights)
                heights.insert(h);

            idx = end;
        }

        int ans = heights.size();
        cout << ans << "\n";
    }
}