#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int r, p;
vector<llong> memo;

llong worst(int n) {
    if (n == 1) return 0LL;

    llong &ans = memo[n];
    if (~ans) return ans;

    ans = LLONG_MAX;
    for (int lo = 2, hi; lo <= n; lo = hi + 1) {
        ans = min(ans, worst((n + lo - 1) / lo) + (lo - 1LL) * p + r);

        int x = (n + lo - 1) / lo;
        if (x == 1) hi = n;
        else hi = (n - 1) / (x - 1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> r >> p;

    memo.assign(n + 5, -1LL);

    llong ans = worst(n);
    cout << ans << "\n";
}