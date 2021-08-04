#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<long, int>> apps(n);
        for (int i = 0; i < n; i++)
            cin >> apps[i].first;

        for (int i = 0; i < n; i++)
            cin >> apps[i].second;

        vector<long> regular;
        vector<long> important;

        for (int i = 0; i < n; i++) {
            if (apps[i].second == 1)
                regular.push_back(apps[i].first);
            else
                important.push_back(apps[i].first);
        }

        sort(regular.rbegin(), regular.rend());
        sort(important.rbegin(), important.rend());

        int rn = regular.size();
        int in = important.size();

        int points = 0;
        long battery = 0LL;

        int r = 0;
        while (r < in && battery < m)
            battery += important[r++], points += 2;

        int l = 0;
        while (l < rn && battery < m)
            battery += regular[l++], points++;

        if (battery < m) {
            cout << "-1\n";
            continue;
        }

        r--;
        while (r >= 0 && battery - important[r] >= m)
            battery -= important[r--], points -= 2;

        int ans = points;
        while (l < rn) {
            points++;
            battery += regular[l++];

            while (r >= 0 && battery - important[r] >= m)
                battery -= important[r--], points -= 2;

            ans = min(ans, points);
        }

        cout << ans << "\n";
    }
}