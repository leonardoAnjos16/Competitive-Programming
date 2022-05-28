#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int n, k;
vector<vector<int>> memo;

int pretty(int used = 0, int prettyness = 0) {
    if (prettyness > k) return 0;

    int i = __builtin_popcount(used);
    if (i >= n) return prettyness == k;

    int &ans = memo[used][prettyness];
    if (~ans) return ans;

    ans = 0;
    for (int j = 0; j < n; j++)
        if (!(used & (1 << j)))
            ans = (ans + pretty(used | (1 << j), prettyness + abs(j - i))) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    memo.assign((1 << n) + 5, vector<int>(k + 5, -1));

    int ans = pretty();
    cout << ans << "\n";
}