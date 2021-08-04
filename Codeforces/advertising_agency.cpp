#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

vector<vector<int>> memo;

int ways(int total, int need, int i = 0, int k = 0) {
    if (k >= need) return 1;
    if (i >= total) return 0;

    int &ans = memo[i][k];
    if (~ans) return ans;

    return ans = (ways(total, need, i + 1, k) + ways(total, need, i + 1, k + 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int last = -1, need = 0;
        for (int i = n - 1; i >= n - k; i--) {
            if (a[i] == last) need++;
            else last = a[i], need = 1;
        }

        int total = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == last) total++;

        memo.assign(total, vector<int>(need, -1));

        int ans = ways(total, need);
        cout << ans << "\n";
    }
}