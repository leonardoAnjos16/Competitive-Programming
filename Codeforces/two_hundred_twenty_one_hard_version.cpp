#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        string s; cin >> s;

        vector<int> ps(n + 1, 0);
        for (int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + (s[i - 1] == '+' ? 1 : -1) * (i & 1 ? 1 : -1);

        while (q--) {
            int l, r;
            cin >> l >> r;

            int sum = ps[r] - ps[l - 1];
            if (!sum) cout << "0\n";
            else {
                vector<int> ans;
                if (!(sum & 1)) {
                    ans.push_back(r);
                    sum = ps[--r] - ps[l - 1];
                }

                assert(abs(sum) & 1);

                int target = abs(sum) / 2 + 1;
                if (sum < 0) target = -target;

                int lo = l, hi = r, m;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    int curr_sum = ps[mid] - ps[l - 1];
                    if (target > 0 && curr_sum < target) lo = mid + 1;
                    else if (target < 0 && curr_sum > target) lo = mid + 1;
                    else hi = mid - 1, m = mid;
                }

                ans.push_back(m);
                sort(ans.begin(), ans.end());

                int cnt = ans.size();
                cout << cnt << "\n";

                for (int i = 0; i < cnt; i++) {
                    if (i) cout << " ";
                    cout << ans[i];
                }

                cout << "\n";
            }
        }
    }
}