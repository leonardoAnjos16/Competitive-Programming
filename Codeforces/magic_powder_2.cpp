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

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; long k;
    cin >> n >> k;

    long a[MAX];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long b[MAX];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    long l = 0, r = 2e9 + 5, ans;
    while (l <= r) {
        long mid = l + (r - l) / 2;

        long extra = 0LL;
        for (int i = 0; i < n && extra <= k; i++)
            extra += max(0LL, a[i] * mid - b[i]);

        if (extra > k) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    cout << ans << "\n";
}