#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int NOANS = 1e9 + 5;

int n, k, x;
vector<int> a, b, c, d;
vector<vector<int>> memo;

int rating(int i = 0, int diff = 0) {
    if (i >= n) return x + diff;
    if (diff < -k) return rating(i + 1, diff + (c[i] ? a[i] : -b[i]));
    if (diff > k) return rating(i + 1, diff + (d[i] ? a[i] : -b[i]));

    int &ans = memo[i][diff + k];
    if (ans != NOANS) return ans;

    ans = rating(i + 1, diff + (c[i] ? a[i] : -b[i]));
    ans = max(ans, rating(i + 1, diff + (d[i] ? a[i] : -b[i])));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> x;

    a.resize(n);
    b.resize(n);
    c.resize(n);
    d.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    memo.assign(n + 5, vector<int>(2 * k + 5, NOANS));

    int ans = rating();
    cout << ans << "\n";
}