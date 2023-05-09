#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

int n, k;
vector<int> a;
vector<vector<int>> memo;

int count(int band = 63, int i = 0) {
    if (i >= n) return __builtin_popcount(band) == k;

    int &ans = memo[band][i];
    if (~ans) return ans;

    ans = count(band, i + 1);
    ans = (ans + count(band & a[i], i + 1)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;

        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        memo.assign(100, vector<int>(n + 5, -1));

        int ans = count();
        if (k == 6) ans = (ans - 1 + MOD) % MOD;

        cout << ans << "\n";
    }
}