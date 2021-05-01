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

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

int memo[25][MAX];

int count(int N, int M) {
    if (!N) return 1LL;
    if (M < 0) return 0LL;

    int &ans = memo[N][M];
    if (~ans) return ans;

    ans = count(N, M - N) % MOD;
    ans += count(N - 1, M) % MOD;

    return ans % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof memo);

    int t; cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        int ans = count(N, M - N * (N + 1) / 2);
        cout << ans << "\n";
    }
}