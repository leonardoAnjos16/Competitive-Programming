#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int pow = 1;
        while (!(n % pow))
            pow <<= 1;

        pow >>= 1;

        vector<int> ans;
        for (int i = 0; i < n / pow; i++)
            ans.push_back(1);

        for (int i = n / pow; i < 2 * n / pow && i < n; i++)
            ans.push_back(3);

        for (int i = 2 * n / pow; i < n; i++)
            ans.push_back(2);

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}