#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int idx = 0;
        vector<bool> ep(n, false);

        while (idx < n && a[idx] == b[idx])
            ep[idx++] = true;

        idx = n - 1;
        vector<bool> es(n, false);

        while (n >= 0 && a[idx] == b[idx])
            es[idx--] = true;

        int l = 0;
        pair<int, int> ans = make_pair(0, -1);

        while (l < n) {
            int r = l;
            while (r + 1 < n && b[r + 1] >= b[r]) r++;

            if ((!l || ep[l - 1]) && (r + 1 >= n || es[r + 1]) && r - l > ans.second - ans.first)
                ans = make_pair(l + 1, r + 1);

            l = r + 1;
        }

        cout << ans.first << " " << ans.second << "\n";
    }
}