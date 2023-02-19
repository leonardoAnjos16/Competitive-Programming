#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int h;
vector<int> x;
vector<vector<llong>> memo;

llong bricks(int l, int r) {
    if (l == r) return h;

    llong &ans = memo[l][r];
    if (~ans) return ans;

    ans = LLONG_MAX;
    for (int i = l; i < r; i++)
        ans = min(ans, bricks(l, i) + bricks(i + 1, r));

    ans -= max(h - (x[r] - x[l] + 1) / 2 + 1, 0);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> h;

    x.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    memo.assign(n + 5, vector<llong>(n + 5, -1LL));

    llong ans = bricks(0, n - 1);
    cout << ans << "\n";
}