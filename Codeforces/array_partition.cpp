#include <bits/stdc++.h>

using namespace std;

#define long long long int

pair<int, int> query(vector<vector<pair<int, int>>> &rmq, int l, int r) {
    int idx = 31 - __builtin_clz(r - l + 1);

    pair<int, int> ans;
    ans.first = min(rmq[idx][l].first, rmq[idx][r - (1 << idx) + 1].first);
    ans.second = max(rmq[idx][l].second, rmq[idx][r - (1 << idx) + 1].second);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int log = 32 - __builtin_clz(n);
        vector<vector<pair<int, int>>> rmq(log, vector<pair<int, int>>(n));

        for (int i = 0; i < n; i++)
            rmq[0][i] = make_pair(a[i], a[i]);

        for (int i = 1; i < log; i++)
            for (int j = 0; j < n - (1 << i) + 1; j++) {
                rmq[i][j].first = min(rmq[i - 1][j].first, rmq[i - 1][j + (1 << (i - 1))].first);
                rmq[i][j].second = max(rmq[i - 1][j].second, rmq[i - 1][j + (1 << (i - 1))].second);
            }

        int x = -1, y = -1, z = -1;
        for (int i = 1; i < n && x == -1; i++) {
            int k = query(rmq, 0, i - 1).second;

            int l = i, r = n - 1, l1 = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                int aux = query(rmq, i, mid).first;

                if (aux > k) l = mid + 1;
                else {
                    r = mid - 1;
                    if (aux == k)
                        l1 = mid;
                }
            }

            l = i; r = n - 1;
            int r1 = -1;

            while (l <= r) {
                int mid = (l + r) / 2;
                int aux = query(rmq, i, mid).first;

                if (aux < k) r = mid - 1;
                else {
                    l = mid + 1;
                    if (aux == k)
                        r1 = mid;
                }
            }

            l = i + 1; r = n - 1;
            int l2 = -1;

            while (l <= r) {
                int mid = (l + r) / 2;
                int aux = query(rmq, mid, n - 1).second;

                if (aux > k) l = mid + 1;
                else {
                    r = mid - 1;
                    if (aux == k)
                        l2 = mid;
                }
            }

            l = i + 1; r = n - 1;
            int r2 = -1;

            while (l <= r) {
                int mid = (l + r) / 2;
                int aux = query(rmq, mid, n - 1).second;

                if (aux < k) r = mid - 1;
                else {
                    l = mid + 1;
                    if (aux == k)
                        r2 = mid;
                }
            }

            if (l1 == -1 || r2 == -1) continue;
            assert(r1 != -1 && l2 != -1);

            if (l1 < r2 && r1 + 1 >= l2) {
                x = i;

                if (r1 < l2) y = r1 - i + 1;
                else if (r1 > l1) y = r1 - i;
                else y = r1 - i + 1; 

                z = n - x - y;
            }
        }

        if (x == -1) cout << "NO\n";
        else cout << "YES\n" << x << " " << y << " " << z << "\n";
    }
}