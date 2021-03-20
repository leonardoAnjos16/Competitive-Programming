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

const int MAX_N = 3e4 + 1;
const int MAX_D = 2e3 + 1;

int cnt[MAX_N] = {0};
int memo[MAX_N][MAX_D];

int gems(int i, int d) {
    if (i > 30000 || !d) return 0;
    if (d < MAX_D && ~memo[i][d]) return memo[i][d];

    int ans = cnt[i] + max({ gems(i + d - 1, d - 1), gems(i + d, d), gems(i + d + 1, d + 1) });
    if (d < MAX_D) memo[i][d] = ans;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        cnt[p]++;
    }

    memset(memo, -1, sizeof memo);

    int ans = gems(d, d);
    cout << ans << "\n";
}