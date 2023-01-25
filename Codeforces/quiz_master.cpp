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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        vector<vector<int>> divs(n);
        for (int i = 0; i < n; i++)
            for (int j = 1; j * j <= a[i]; j++)
                if (!(a[i] % j)) {
                    divs[i].push_back(j);
                    if (j * j < a[i])
                        divs[i].push_back(a[i] / j);
                }

        vector<int> cover(m, 0);
        int cnt = 0, l = 0, r = 0, ans = INT_MAX;

        while (r < n) {
            while (r < n && cnt < m) {
                for (int div: divs[r])
                    if (div <= m && cover[div - 1]++ == 0) cnt++;

                r++;
            }

            while (l < r && cnt >= m) {
                ans = min(ans, a[r - 1] - a[l]);
                for (int div: divs[l])
                    if (div <= m && --cover[div - 1] == 0) cnt--;

                l++;
            }
        }

        if (ans == INT_MAX) ans = -1;
        cout << ans << "\n";
    }
}