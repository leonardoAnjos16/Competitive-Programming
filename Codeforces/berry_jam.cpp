#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++)
            cin >> a[i];

        vector<int> diff(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; i++)
            diff[i] = diff[i - 1] + (a[i] == 1 ? 1 : -1);

        map<int, int> dist;
        for (int i = n + 1; i <= 2 * n; i++)
            if (!dist.count(diff[i] - diff[n]))
                dist[diff[i] - diff[n]] = i - n;

        int ans = 2 * n;
        for (int i = 0; i <= n; i++) {
            int need = diff[2 * n] - (diff[n] - diff[n - i]);
            if (!need)
                ans = min(ans, i);
            else if (dist.count(need))
                ans = min(ans, i + dist[need]);
        }

        cout << ans << "\n";
    }
}