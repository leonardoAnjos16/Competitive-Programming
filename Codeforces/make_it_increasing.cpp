#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0;
        bool possible = true;

        for (int i = n - 2; i >= 0 && possible; i--) {
            while (a[i] && a[i] >= a[i + 1]) {
                ans++;
                a[i] /= 2;
            }

            if (a[i] >= a[i + 1]) possible = false;
        }

        if (!possible) cout << "-1\n";
        else cout << ans << "\n";
    }
}