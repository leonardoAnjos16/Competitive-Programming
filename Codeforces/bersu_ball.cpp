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

const int MAX = 105;

int n, a[MAX];
int m, b[MAX];
int memo[MAX][MAX];

int pairs(int i = 0, int j = 0) {
    if (i >= n || j >= m) return 0;

    int &ans = memo[i][j];
    if (~ans) return ans;

    ans = max(pairs(i + 1, j), pairs(i, j + 1));
    if (abs(a[i] - b[j]) <= 1)
        ans = max(ans, 1 + pairs(i + 1, j + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(b, b + m);

    memset(memo, -1, sizeof memo);

    int ans = pairs();
    cout << ans << "\n";
}