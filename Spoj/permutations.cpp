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

const int MAX_N = 15;
const int MAX_K = 100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[MAX_N][MAX_K] = {0};

    dp[1][0] = 1;
    for (int i = 2; i <= 12; i++)
        for (int j = 0; j <= i * (i - 1) / 2; j++)
            for (int k = 0; k <= min(i - 1, j); k++)
                dp[i][j] += dp[i - 1][j - k];

    int d; cin >> d;
    while (d--) {
        int n, k;
        cin >> n >> k;

        int ans = dp[n][k];
        cout << ans << "\n";
    }
}