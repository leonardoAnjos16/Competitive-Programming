#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(a.begin(), a.begin() + i, make_pair(x - a[i].first, 0));
        if (it != a.begin() + i && it->first == x - a[i].first) {
            cout << it->second << " " << a[i].second << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
}