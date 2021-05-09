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

const int MAX = 1e3 + 5;

int n, m, x, y;
string a[MAX];
int memo[MAX][MAX];

int price(int i = 0, int j = 0) {
    if (i >= n) return 0;
    if (j >= m) return price(i + 1);

    int &ans = memo[i][j];
    if (~ans) return ans;

    if (a[i][j] == '*')
        return ans = price(i, j + 1);

    ans = x + price(i, j + 1);
    if (j + 1 < m && a[i][j + 1] == '.')
        ans = min(ans, y + price(i, j + 2));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        memset(memo, -1, sizeof memo);

        int ans = price();
        cout << ans << "\n";
    }
}