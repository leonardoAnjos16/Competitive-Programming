#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> x(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];

        sort(x.begin(), x.end());

        int ans = 2 * (x[n - 1] - x[0]);
        cout << ans << "\n";
    }
}