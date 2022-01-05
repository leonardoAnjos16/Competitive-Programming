#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int cnt = 0;
        vector<string> ans(n, string(n, '.'));

        for (int i = 0; i < n && cnt < k; i += 2, cnt++)
            ans[i][i] = 'R';

        if (cnt < k) cout << "-1\n";
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << ans[i][j];

                cout << "\n";
            }
        }
    }
}