#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong NOANS = -1e18;

int n;
vector<int> l, r;
vector<vector<llong>> memo;

llong max_horizontal_distance(int i = 0, int left = 0) {
    if (i >= n) return 0LL;

    llong &ans = memo[i][left];
    if (ans != NOANS) return ans;

    int right = i - left;
    ans = l[i] * (2LL * left - n + 1LL) + max_horizontal_distance(i + 1, left + 1);
    ans = max(ans, r[i] * (2LL * (n - right - 1LL) - n + 1LL) + max_horizontal_distance(i + 1, left));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    l.resize(n);
    r.resize(n);

    for (int i = 0; i < n; i++)
        cin >> l[n - i - 1] >> r[n - i - 1];

    memo.assign(n + 5, vector<llong>(n + 5, NOANS));

    llong ans = max_horizontal_distance();
    for (int i = 0; i < n; i++)
        ans += i * (i + 1LL) / 2LL;

    cout << ans << "\n";
}