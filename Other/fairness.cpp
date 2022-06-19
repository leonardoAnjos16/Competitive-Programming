#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

int n;
vector<int> a, sums;
vector<vector<int>> memo;

int unfairness(int i = 0, int sum = 0) {
    if (i >= n) return INT_MIN;

    int &ans = memo[i][sum];
    if (~ans) return ans;

    int other_sum = sums[i] - sum;
    ans = max(abs(sum + a[i] - other_sum), unfairness(i + 1, sum + a[i]));
    ans = min(ans, max(abs(sum - other_sum - a[i]), unfairness(i + 1, sum)));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;

        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sums.assign(n, 0);
        for (int i = 1; i < n; i++)
            sums[i] = sums[i - 1] + a[i - 1];

        memo.assign(n + 5, vector<int>(MAX, -1));

        int ans = unfairness();
        cout << ans << "\n";
    }
}