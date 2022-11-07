#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int idx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin() + idx, b.end(), a[i] - k);
        if (it != b.end() && abs(a[i] - *it) <= k) idx = it - b.begin() + 1, ans++;
    }

    cout << ans << "\n";
}