#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;

    vector<pair<int, int>> segs(n);
    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        segs[i] = make_pair(x1, x2);
    }

    vector<long> dists(n, 0LL);
    for (int i = 1; i < n; i++)
        dists[i] = dists[i - 1] + segs[i].first - segs[i - 1].second;

    long ans = 0LL;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(dists.begin(), dists.end(), h + dists[i]) - dists.begin() - 1;
        long end = segs[idx].second + h + dists[i] - dists[idx];
        ans = max(ans, end - segs[i].first);
    }

    cout << ans << "\n";
}