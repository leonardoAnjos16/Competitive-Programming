#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(m);
        for (int i = 0; i < m; i++)
            cin >> b[i];

        vector<int> ans(n + m);
        int i = 0, j = 0, l = 0;

        while (i < n || j < m) {
            if (i >= n) ans[l++] = b[j++];
            else if (j >= m) ans[l++] = a[i++];
            else if (a[i] < b[j]) ans[l++] = a[i++];
            else ans[l++] = b[j++];
        }

        bool possible = true;
        for (int i = 0; i < n + m && possible; i++) {
            if (!ans[i]) k++;
            else if (ans[i] > k) possible = false;
        }

        if (!possible) cout << "-1\n";
        else {
            for (int i = 0; i < n + m; i++) {
                if (i) cout << " ";
                cout << ans[i];
            }

            cout << "\n";
        }
    }
}