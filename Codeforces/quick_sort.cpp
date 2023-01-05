#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        int cnt = 0, nxt = 1;
        for (int i = 0; i < n; i++)
            if (p[i] == nxt) cnt++, nxt++;

        int ans = (n - cnt + k - 1) / k;
        cout << ans << "\n";
    }
}