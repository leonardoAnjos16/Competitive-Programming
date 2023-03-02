#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int n, k, x;
vector<int> a;
vector<vector<vector<llong>>> memo;

llong sum(int inside = 0, int i = 0, int inc = 0) {
    if (inc > k) return -INF;
    if (i >= n) return inc == k ? 0LL : -INF;

    llong &ans = memo[inside][i][inc];
    if (~ans) return ans;

    llong first, second;
    if (!inside) {
        first = max(sum(0, i + 1, inc), max(sum(1, i + 1, inc), sum(2, i + 1, inc)) + a[i] - x);
        second = max(sum(0, i + 1, inc + 1), max(sum(1, i + 1, inc + 1), sum(2, i + 1, inc + 1)) + a[i] + x);
    } else if (inside == 1) {
        first = max(sum(1, i + 1, inc), sum(2, i + 1, inc)) + a[i] - x;
        second = max(sum(1, i + 1, inc + 1), sum(2, i + 1, inc + 1)) + a[i] + x;
    } else {
        first = sum(2, i + 1, inc);
        second = sum(2, i + 1, inc + 1);
    }

    return ans = max(first, second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> k >> x;

        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        memo.assign(5, vector<vector<llong>>(n + 5, vector<llong>(k + 5, -1LL)));

        llong ans = sum();
        cout << ans << "\n";
    }
}