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

int n, a[MAX];
long memo[MAX];

long score(int i) {
    if (i >= n) return 0LL;

    long &ans = memo[i];
    if (~ans) return ans;

    return ans = a[i] + score(i + a[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        memset(memo, -1, sizeof memo);

        long ans = 0LL;
        for (int i = 0; i < n; i++)
            ans = max(ans, score(i));

        cout << ans << "\n";
    }
}