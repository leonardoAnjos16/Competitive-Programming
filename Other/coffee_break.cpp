#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d;
    cin >> n >> m >> d;

    vector<int> a(n);
    multiset<pair<int, int>> minutes;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        minutes.emplace(a[i], i);
    }

    int cnt = 0;
    vector<int> ans(n);

    while (!minutes.empty()) {
        int minute = minutes.begin()->first;
        ans[minutes.begin()->second] = ++cnt;
        minutes.erase(minutes.begin());

        multiset<pair<int, int>>::iterator it;
        while ((it = minutes.upper_bound(make_pair(minute + d, n))) != minutes.end()) {
            ans[it->second] = cnt;
            minute = it->first;
            minutes.erase(it);
        }
    }

    cout << cnt << "\n";
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}