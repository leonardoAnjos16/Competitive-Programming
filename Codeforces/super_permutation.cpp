#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        if (n == 1) cout << "1\n";
        else if (n & 1) cout << "-1\n";
        else {
            vector<int> ans(n);
            ans[0] = n;
            ans[1] = n - 1;

            for (int i = 2; i < n; i++) {
                if (!(i & 1)) ans[i] = (ans[i - 2] + 2) % n;
                else ans[i] = (ans[i - 2] - 2 + n) % n;
            }

            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << ans[i];
            }

            cout << "\n";
        }
    }
}