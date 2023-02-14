#include <bits/stdc++.h>

using namespace std;

vector<int> pos;

pair<int, int> solve(int l, int r, int mn, int mx) {
    if (r - l <= 1) return make_pair(-1, -1);

    int i = pos[mn], j = pos[mx];
    if (i != l && i != r && j != l && j != r)
        return make_pair(min(i, j) - 1, max(i, j) + 1);

    if (min(i, j) == l && max(i, j) == r)
        return solve(l + 1, r - 1, mn + 1, mx - 1);

    if (i == l) return solve(l + 1, r, mn + 1, mx);
    if (i == r) return solve(l, r - 1, mn + 1, mx);

    if (j == l) return solve(l + 1, r, mn, mx - 1);

    assert(j == r);
    return solve(l, r - 1, mn, mx - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        pos.resize(n);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            pos[a - 1] = i;
        }

        auto [l, r] = solve(0, n - 1, 0, n - 1);
        if (l == -1) cout << "-1\n";
        else cout << (l + 1) << " " << (r + 1) << "\n";
    }
}