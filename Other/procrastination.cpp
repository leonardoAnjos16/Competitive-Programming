#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k, n;
    cin >> k >> n;

    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(c.begin(), c.end());

    int sum = 0;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        ans[c[i].second] = min(k - sum, c[i].first);
        sum += ans[c[i].second];
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}