#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> b(n * m);
        for (int i = 0; i < n * m; i++)
            cin >> b[i];

        sort(b.begin(), b.end());

        int ans = b[n * m - 1] * (n * m - 1) - b[0] * (n * m - n) - b[1] * (n - 1);
        ans = max(ans, b[n * m - 1] * (n * m - 1) - b[0] * (n * m - m) - b[1] * (m - 1));
        ans = max(ans, b[n * m - 1] * (n * m - n) + b[n * m - 2] * (n - 1) - b[0] * (n * m - 1));
        ans = max(ans, b[n * m - 1] * (n * m - m) + b[n * m - 2] * (m - 1) - b[0] * (n * m - 1));

        cout << ans << "\n";
    }
}