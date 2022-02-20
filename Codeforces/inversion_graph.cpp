#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        stack<pair<int, int>> segs;
        for (int i = 0; i < n; i++) {
            bool merged = true;
            segs.emplace(p[i], p[i]);

            while ((int) segs.size() >= 2 && merged) {
                pair<int, int> last = segs.top(); segs.pop();
                pair<int, int> slast = segs.top(); segs.pop();

                if (slast.second > last.first) {
                    int mn = min(last.first, slast.first);
                    int mx = max(last.second, slast.second);
                    segs.emplace(mn, mx);
                } else {
                    segs.push(slast);
                    segs.push(last);
                    merged = false;
                }
            }
        }

        int ans = segs.size();
        cout << ans << "\n";
    }
}