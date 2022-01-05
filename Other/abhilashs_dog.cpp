#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m; cin >> m;
    int n; cin >> n;

    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;

        sum += t;
        if (sum <= m)
            ans++;
    }

    cout << ans << "\n";
}