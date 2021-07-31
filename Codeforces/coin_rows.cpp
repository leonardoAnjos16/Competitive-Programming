#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int m; cin >> m;

        vector<int> ps1(m + 1, 0);
        for (int i = 1; i <= m; i++) {
            cin >> ps1[i];
            ps1[i] += ps1[i - 1];
        }

        vector<int> ps2(m + 1, 0);
        for (int i = 1; i <= m; i++) {
            cin >> ps2[i];
            ps2[i] += ps2[i - 1];
        }

        int ans = INT_MAX;
        for (int i = 1; i <= m; i++)
            ans = min(ans, max(ps1[m] - ps1[i], ps2[i - 1]));

        cout << ans << "\n";
    }
}