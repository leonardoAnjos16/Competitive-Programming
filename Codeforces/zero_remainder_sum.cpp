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

const int MAX = 70;

int n, m, k, a[MAX][MAX];
int memo[MAX][MAX][MAX][MAX];

int sum(int i = 0, int j = 0, int mod = 0, int cnt = 0) {
    if (i >= n) return 0;
    if (j >= m || cnt >= m / 2) return sum(i + 1, 0, mod);

    int &ans = memo[i][j][mod][cnt];
    if (~ans) return ans;

    ans = sum(i, j + 1, mod, cnt);
    int new_mod = (mod + k - (a[i][j] % k)) % k;

    int x = sum(i, j + 1, new_mod, cnt + 1);
    if (x || !new_mod) ans = max(ans, x + a[i][j]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    memset(memo, -1, sizeof memo);

    int ans = sum();
    cout << ans << "\n";
}