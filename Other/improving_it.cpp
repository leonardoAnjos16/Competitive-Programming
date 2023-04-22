#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n, m;
vector<vector<int>> c;
vector<llong> memo;

llong cost(int i = 0) {
    if (i >= n) return 0LL;

    llong &ans = memo[i];
    if (~ans) return ans;

    ans = LLONG_MAX;
    for (int j = 1; j <= min(m, n - i); j++)
        ans = min(ans, c[i][0] - c[i][j] + cost(i + j));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    c.resize(n);
    for (int i = 0; i < n; i++) {
        c[i].resize(min(m, n - i) + 1);
        for (int j = 0; j < (int) c[i].size(); j++)
            cin >> c[i][j];
    }

    memo.assign(n + 5, -1LL);

    llong ans = cost();
    cout << ans << "\n";
}