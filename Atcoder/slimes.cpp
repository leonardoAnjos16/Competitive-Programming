#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<long> a, sum;
vector<vector<long>> memo;

long cost(int i, int j) {
    if (i >= j) return 0LL;

    long &ans = memo[i][j];
    if (~ans) return ans;

    ans = LLONG_MAX;
    for (int k = i + 1; k <= j; k++)
        ans = min(ans, sum[j] - sum[i - 1] + cost(i, k - 1) + cost(k, j));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    a.resize(N + 1);
    sum.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    memo.assign(N + 5, vector<long>(N + 5, -1LL));

    long ans = cost(1, N);
    cout << ans << "\n";
}