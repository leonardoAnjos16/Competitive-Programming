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

        int ans = 0, idx = 0;
        while (idx < n) {
            while (idx < n && a[idx]) idx++;

            int cnt = 0;
            while (idx < n && !a[idx])
                cnt++, idx++;

            ans = max(ans, cnt);
        }

        cout << ans << "\n";
    }
}