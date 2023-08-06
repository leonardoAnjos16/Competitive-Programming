#include <bits/stdc++.h>

using namespace std;

int solve(vector<pair<int, int>> &points, int ws) {
    int idx = 0, bs = 0, ans = INT_MIN;
    while (idx < (int) points.size()) {
        if (points[idx].second == 'b') bs++;
        else ws--;

        while (idx + 1 < (int) points.size() && points[idx + 1].first == points[idx].first) {
            idx++;
            if (points[idx].second == 'b') bs++;
            else ws--;
        }

        idx++;
        ans = max(ans, bs + ws);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int all_ws = 0;
    vector<pair<int, int>> xs(N), ys(N);

    for (int i = 0; i < N; i++) {
        int x, y; char p;
        cin >> x >> y >> p;

        all_ws += p == 'w';
        xs[i] = make_pair(x, p);
        ys[i] = make_pair(y, p);
    }

    sort(xs.begin(), xs.end());
    int ans = solve(xs, all_ws);

    reverse(xs.begin(), xs.end());
    ans = max(ans, solve(xs, all_ws));

    sort(ys.begin(), ys.end());
    ans = max(ans, solve(ys, all_ws));

    reverse(ys.begin(), ys.end());
    ans = max(ans, solve(ys, all_ws));

    cout << ans << "\n";
}