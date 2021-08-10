#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> ls(n), rs(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        ls[i] = make_pair(l, i);
        rs[i] = make_pair(r, i);
    }

    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end());

    int ans = 0, i = n - 1, j = 0;
    if (ls[i].second == rs[j].second)
        ans = max(ans, rs[j + 1].first - ls[i - 1].first);
    else {
        ans = max(ans, rs[j].first - ls[i - 1].first);
        ans = max(ans, rs[j + 1].first - ls[i].first);
    }

    cout << ans << "\n";
}