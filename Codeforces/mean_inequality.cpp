#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++)
            ans[2 * i] = a[i];

        for (int i = 0; i < n; i++)
            ans[2 * i + 1] = a[i + n];

        for (int i = 0; i < 2 * n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}