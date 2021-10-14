#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

vector<int> memo;

int count(int n) {
    if (n < 0) return 0;
    if (!n) return 1;

    int &ans = memo[n];
    if (~ans) return ans;

    ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += count(n - i);
        ans %= MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    memo.assign(n + 5, -1);

    int ans = count(n);
    cout << ans << "\n";
}