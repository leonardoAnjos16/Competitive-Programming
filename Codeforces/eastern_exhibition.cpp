#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        if (n & 1) cout << "1\n";
        else {
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());

            int dx = x[n / 2] - x[n / 2 - 1];
            int dy = y[n / 2] - y[n / 2 - 1];

            long ans = (dx + 1LL) * (dy + 1LL);
            cout << ans << "\n";
        }
    }
}