#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 105;

int n; long a[MAX];
long memo[MAX * MAX];

long energy(int k) {
    if (k <= n) return a[k - 1];

    long &ans = memo[k];
    if (~ans) return ans;

    ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, energy(i + 1) + energy(k - i - 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int optimal = 1;
    for (int i = 1; i < n; i++)
        if (a[i] * optimal < a[optimal - 1] * (i + 1))
            optimal = i + 1;

    memset(memo, -1, sizeof memo);
    while (q--) {
        int k; cin >> k;

        // k - q * optimal <= n * (n + 1)
        // q * optimal >= k - n * (n + 1)
        // q >= (k - n * (n + 1)) / optimal
        // q = (k - n * (n + 1) + optimal - 1) / optimal

        long ans = 0LL;
        if (k > n * (n + 1)) {
            long aux = (k - n * (n + 1) + optimal - 1) / optimal;
            ans += aux * a[optimal - 1];
            k -= aux * optimal;
        }

        ans += energy(k);
        cout << ans << "\n";
    }
}