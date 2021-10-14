#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e8;

int n, x;
vector<int> c;
vector<int> memo;

int coins(int sum = 0) {
    if (sum > x) return INF;
    if (sum == x) return 0;

    int &ans = memo[sum];
    if (~ans) return ans;

    ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, coins(sum + c[i]) + 1);

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

    int ans = coins();
    if (ans >= INF) cout << "-1\n";
    else cout << ans << "\n";
}