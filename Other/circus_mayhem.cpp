#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> ps;
vector<vector<int>> memo;

int cost(int l, int r) {
    int sum = ps[r] - ps[l - 1];
    if (l == r) return 0;

    int &ans = memo[l][r];
    if (~ans) return ans;

    ans = INT_MAX;
    for (int i = l + 1; i <= r; i++)
        ans = min(ans, cost(l, i - 1) + cost(i, r) + sum);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    ps.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }

    memo.assign(n + 1, vector<int>(n + 1, -1));

    int ans = cost(1, n);
    cout << ans << "\n";
}