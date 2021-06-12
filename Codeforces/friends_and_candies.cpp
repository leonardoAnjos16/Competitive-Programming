#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int sum = 0;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % n) cout << "-1\n";
        else {
            int target = sum / n;

            int ans = 0;
            for (int i = 0; i < n; i++)
                if (a[i] > target) ans++;

            cout << ans << "\n";
        }
    }
}