#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int l = 1, r = n + 1;
        vector<vector<int>> ans(2, vector<int>(n));

        for (int i = 0; i < n; i++) {
            if (!(i & 1)) {
                ans[1][i] = l++;
                ans[0][i + 1] = l++;
            } else {
                ans[1][i] = r++;
                ans[0][(i + 1) % n] = r++;
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if (j) cout << " ";
                cout << ans[i][j];
            }

            cout << "\n";
        }
    }
}