#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> bl(n);
        bl[0] = b[0];

        for (int i = 1; i < n; i++)
            bl[i] = max(bl[i - 1], b[i] + i);

        vector<int> br(n);
        br[n - 1] = b[n - 1] - n + 1;

        for (int i = n - 2; i >= 0; i--)
            br[i] = max(br[i + 1], b[i] - i);

        int ans = INT_MIN;
        for (int i = 1; i + 1 < n; i++)
            ans = max(ans, bl[i - 1] + b[i] + br[i + 1]);

        cout << ans << "\n";
    }
}