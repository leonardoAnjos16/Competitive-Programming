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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int a[MAX];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int dp[MAX][2] = {0};
    dp[1][0] = dp[1][1] = 1;

    int ans = INT_MIN;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] <= a[i - 2]) dp[i][0] = 1;
        else dp[i][0] = dp[i - 1][0] + 1;

        dp[i][1] = 1;
        if (a[i - 1] > a[i - 3]) dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
        if (a[i - 1] > a[i - 2]) dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);

        ans = max({ ans, dp[i][0], dp[i][1] });
    }

    cout << ans << "\n";
}