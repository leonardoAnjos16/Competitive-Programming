#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

int n, k;
vector<int> p;
vector<vector<int>> w;
vector<vector<vector<int>>> memo;

int points(bool part = false, int i = 0, int sum = 0) {
    if (sum > k) return -INF;
    if (i >= n) return (sum == k ? 0 : -INF);

    int &ans = memo[part][i][sum];
    if (~ans) return ans;

    ans = points(part, i + 1, sum);
    ans = max(ans, points(part, i + 1, sum + p[i]) + w[i].back());

    if (!part)
        for (int j = 0; j < p[i]; j++)
            ans = max(ans, points(true, i + 1, sum + j + 1) + w[i][j]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    p.resize(n);
    w.resize(n);

    int sump = 0, sumw = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sump += p[i];

        w[i].resize(p[i]);
        for (int j = 0; j < p[i]; j++)
            cin >> w[i][j];

        sumw += w[i].back();
    }

    if (sump <= k) cout << sumw << "\n";
    else {
        memo.assign(2, vector<vector<int>>(n + 5, vector<int>(k + 5, -1)));

        int ans = points();
        cout << ans << "\n";
    }
}