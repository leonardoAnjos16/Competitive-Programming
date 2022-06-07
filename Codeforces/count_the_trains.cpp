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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        set<pair<int, int>> vp, pv;
        vp.emplace(a[0], 0);
        pv.emplace(0, a[0]);

        int curr = a[0];
        for (int i = 1; i < n; i++)
            if (a[i] < curr) {
                vp.emplace(a[i], i);
                pv.emplace(i, a[i]);
                curr = a[i];
            }

        for (int i = 0; i < m; i++) {
            int k, d;
            cin >> k >> d;

            auto it = pv.upper_bound(make_pair(k - 1, INT_MAX));
            assert(it != pv.begin());
            it--;

            if (a[k - 1] - d < it->second) {
                auto begin_vp = vp.lower_bound(make_pair(a[k - 1] - d, 0));
                auto end_vp = vp.upper_bound(make_pair(it->second, INT_MAX));

                if (it->first < k - 1)
                    end_vp--;

                auto begin_pv = pv.begin();
                if (end_vp != vp.end()) {
                    begin_pv = pv.find(make_pair(end_vp->second, end_vp->first));
                    begin_pv++;
                }

                auto end_pv = pv.find(make_pair(begin_vp->second, begin_vp->first));
                end_pv++;

                vp.erase(begin_vp, end_vp);
                pv.erase(begin_pv, end_pv);

                vp.emplace(a[k - 1] - d, k - 1);
                pv.emplace(k - 1, a[k - 1] - d);
            }

            a[k - 1] -= d;

            if (i) cout << " ";

            int ans = vp.size();
            cout << ans;
        }

        cout << "\n";
    }
}