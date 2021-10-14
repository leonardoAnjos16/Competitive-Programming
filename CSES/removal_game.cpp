#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<long> x, ps;
vector<vector<long>> memo;

long score(int l, int r) {
    if (l > r) return 0;

    long &ans = memo[l][r];
    if (~ans) return ans;

    ans = x[l] + ps[r] - ps[l] - score(l + 1, r);
    ans = max(ans, x[r] + ps[r - 1] - ps[l - 1] - score(l, r - 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    x.assign(n + 1, 0);
    ps.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        ps[i] = ps[i - 1] + x[i];
    }

    memo.assign(n + 5, vector<long>(n + 5, -1));

    long ans = score(1, n);
    cout << ans << "\n";
}