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

const int MAX = 2e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[MAX] = {0};
    dp[0] = dp[1] = -1;

    for (int i = 2; i < MAX; i++) {
        for (int j = 2 * i; j < MAX; j += i)
            dp[j] += i;

        dp[i] = dp[i] + 1 == i ? i : dp[i - 1];
    }

    int n; cin >> n;
    while (n--) {
        int k; cin >> k;
        cout << dp[k] << "\n";
    }
}