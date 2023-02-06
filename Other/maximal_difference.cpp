#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int N;
vector<vector<vector<llong>>> memo;

llong pow(llong a, int n) {
    if (!n) return 1LL;

    llong ans = pow(a, n >> 1);
    ans *= ans;

    if (!(n & 1)) return ans;
    return ans * a;
}

llong difference(int i = 0, int sum_a = 0, int sum_b = 0) {
    if (i >= N) return sum_a == sum_b ? 0 : -INF;

    llong &ans = memo[i][sum_a][sum_b];
    if (~ans) return ans;

    ans = -INF;
    for (int da = (!i ? 1 : 0); da < 10; da++)
        for (int db = (!i ? 1 : 0); db < 10; db++)
            ans = max(ans, difference(i + 1, sum_a + da, sum_b + db) + (da - db) * pow(10LL, N - i - 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    memo.assign(N + 5, vector<vector<llong>>(10 * N, vector<llong>(10 * N, -1LL)));

    llong ans = difference();
    cout << ans << "\n";
}