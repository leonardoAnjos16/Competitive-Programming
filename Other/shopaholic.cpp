#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        sort(p.rbegin(), p.rend());

        int ans = 0;
        for (int i = 2; i < n; i += 3)
            ans += p[i];

        cout << ans << "\n";
    }
}