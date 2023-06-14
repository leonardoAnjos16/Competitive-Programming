#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<pair<int, int>> segments;
vector<int> memo;

int pairs(int i = 0) {
    if (i >= n) return 0;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = pairs(i + 1);
    for (int j = i + 1; j < n && segments[j].first <= segments[i].second; j++) {
        int nxt = upper_bound(segments.begin(), segments.end(), make_pair(max(segments[i].second, segments[j].second), INT_MAX)) - segments.begin();
        ans = max(ans, pairs(nxt) + 1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;

        segments.resize(n);
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            segments[i] = make_pair(l, r);
        }

        sort(segments.begin(), segments.end());

        memo.assign(n + 5, -1);

        int ans = n - 2 * pairs();
        cout << ans << "\n";
    }
}