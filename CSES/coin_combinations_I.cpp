#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int n, x;
vector<int> c;
vector<int> memo;

int count(int sum = 0) {
    if (sum > x) return 0;
    if (sum == x) return 1;

    int &ans = memo[sum];
    if (~ans) return ans;

    ans = 0;
    for (int i = 0; i < n; i++) {
        ans += count(sum + c[i]);
        ans %= MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    c.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    memo.assign(x + 5, -1);

    int ans = count();
    cout << ans << "\n";
}