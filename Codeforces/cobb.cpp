#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int start = max(n - MAX, 0);

        long ans = LLONG_MIN;
        for (int i = start; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = max(ans, (i + 1LL) * (j + 1LL) - 1LL * k * (a[i] | a[j]));

        cout << ans << "\n";
    }
}