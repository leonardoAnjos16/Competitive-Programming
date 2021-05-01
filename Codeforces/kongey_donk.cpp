#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;
const long INF = 1e18;

int n, h;
vector<vi> bananas;
vector<vector<long>> memo;

long max_bananas(int i, int j = 0) {
    if (i < 0 || i >= n) return -INF;
    if (j >= h) return 0LL;

    long &ans = memo[i][j];
    if (~ans) return ans;

    return ans = max({ max_bananas(i - 1, j + 1), max_bananas(i, j + 1), max_bananas(i + 1, j + 1) }) + bananas[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h;
    bananas.assign(n, vi(h));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < h; j++)
            cin >> bananas[i][j];

    memo.assign(n, vector<long>(h, -1LL));

    long ans = -INF;
    for (int i = 0; i < n; i++)
        ans = max(ans, max_bananas(i));

    cout << ans << "\n";
}