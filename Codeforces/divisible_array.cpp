#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> ans(n);

        int sum = 0;
        for (int i = 1; i < n; i++) {
            ans[i] = i + 1;
            sum += i + 1;
        }

        if (!(sum % n)) ans[0] = n;
        else ans[0] = n - (sum % n);

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}