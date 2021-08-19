#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long> reds(n);
    for (int i = 0; i < n; i++) {
        long x, u;
        cin >> x >> u;
        reds[i] = x * u;
    }

    multiset<long> blues;
    for (int i = 0; i < m; i++) {
        long y, v;
        cin >> y >> v;
        blues.insert(y * v);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = blues.lower_bound(reds[i]);
        if (it != blues.end() && *it == reds[i]) {
            ans++;
            blues.erase(it);
        }
    }

    cout << ans << "\n";
}