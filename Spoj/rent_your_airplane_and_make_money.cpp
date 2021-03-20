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

const int MAX = 1e4 + 5;

int n;
pair<pii, int> orders[MAX];
long memo[MAX];

long profit(int i) {
    long &ans = memo[i];
    if (~ans) return ans;

    int next = orders[i].fst.fst + orders[i].fst.snd;
    int idx = lower_bound(orders, orders + n, make_pair(make_pair(next, 0), 0)) - orders;

    ans = 0LL;
    for (int i = idx; i < n; i++)
        ans = max(ans, profit(i));

    ans += orders[i].snd;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int st, d, p;
            cin >> st >> d >> p;
            orders[i] = { { st, d }, p };
        }

        sort(orders, orders + n);
        memset(memo, -1, sizeof memo);

        long ans = -1;
        for (int i = 0; i < n; i++)
            ans = max(ans, profit(i));

        cout << ans << "\n";
    }
}