#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("plants.in", "r", stdin);

    int n; cin >> n;

    vector<long> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<long> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    pair<long, long> ans = make_pair(0LL, LLONG_MAX);
    for (int i = 1; i < n; i++) {
        if (h[i - 1] > h[i] && g[i - 1] >= g[i]) {
            cout << "-1\n";
            return 0;
        }

        if (h[i - 1] <= h[i]) {
            if (g[i - 1] > g[i]) {
                long t = (h[i] - h[i - 1]) / (g[i - 1] - g[i]);
                ans.second = min(ans.second, t);
            }
        } else {
            long t = (h[i - 1] - h[i] + g[i] - g[i - 1] - 1) / (g[i] - g[i - 1]);
            ans.first = max(ans.first, t);
        }

        // h(i - 1) + g(i - 1) * t <= h(i) + g(i) * t
        // t * (g(i) - g(i - 1)) >= h(i - 1) - h(i)
        // t >= (h(i - 1) - h(i)) / (g(i) - g(i - 1))
    }

    if (ans.first > ans.second) cout << "-1\n";
    else cout << ans.first << "\n";
}