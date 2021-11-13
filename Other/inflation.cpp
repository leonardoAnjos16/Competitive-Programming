#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(c.begin(), c.end());

    bool possible = true;
    long double ans = 1.0;

    for (int i = 0; i < n && possible; i++) {
        ans = min(ans, (long double) c[i] / (i + 1.0));
        if (c[i] > i + 1) possible = false;
    }

    if (!possible) cout << "-1\n";
    else cout << ans << "\n";
}