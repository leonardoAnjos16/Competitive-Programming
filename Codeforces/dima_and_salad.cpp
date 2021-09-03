#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e6 + 5;

int n, k;
vector<int> a, b;
vector<map<int, int>> memo;

int sum(int i = 0, int diff = 0) {
    if (i >= n) return !diff ? 0 : -INF;

    if (memo[i].count(diff))
        return memo[i][diff];

    return memo[i][diff] = max(sum(i + 1, diff), a[i] + sum(i + 1, diff + a[i] - k * b[i]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    memo.assign(n + 5, map<int, int>());

    int ans = sum();
    if (!ans) ans = -1;
    cout << ans << "\n";
}