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

const long INF = 1e18;
const int MAX = 5e3 + 5;

int n, m, k;
long ps[MAX] = {0};
long memo[MAX][MAX];

long sum(int i = 0, int cnt = 0) {
    if (i + m > n || cnt >= k) return 0;

    long &ans = memo[i][cnt];
    if (~ans) return ans;

    return ans = max(sum(i + 1, cnt), sum(i + m, cnt + 1) + ps[i + m] - ps[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }

    memset(memo, -1, sizeof memo);

    long ans = sum();
    cout << ans << "\n";
}