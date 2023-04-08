#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k, mx;
vector<int> c;
vector<vector<vector<int>>> memo;

int size(int i = 0, int last = 0, int m = 0) {
    if (i >= n) return !m ? 0 : -INF;

    int &ans = memo[i][last][m];
    if (~ans) return ans;

    ans = size(i + 1, last, m);
    if (!m || c[i] == last)
        ans = max(ans, size(i + 1, c[i], (m + 1) % k) + 1);

    return ans;
}

int paths(int i = 0, int last = 0, int s = 0) {
    if (s > mx) return 0;
    if (i >= n) return s >= mx;

    int &ans = memo[i][last][s];
    if (~ans) return ans;

    ans = paths(i + 1, last, s);
    if (!(s % k) || c[i] == last)
        ans = (ans + paths(i + 1, c[i], s + 1)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;

        c.resize(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];

        memo.assign(n + 5, vector<vector<int>>(n + 5, vector<int>(k + 5, -1)));

        mx = size();

        memo.assign(n + 5, vector<vector<int>>(n + 5, vector<int>(mx + 5, -1)));

        int ans = paths();
        cout << ans << "\n";
    }
}