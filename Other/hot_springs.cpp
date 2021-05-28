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

    int n; cin >> n;

    int t[MAX];
    for (int i = 0; i < n; i++)
        cin >> t[i];

    sort(t, t + n);

    vi ans;
    for (int i = 0; i < n / 2; i++) {
        ans.pb(t[i]);
        ans.pb(t[n - i - 1]);
    }

    if (n & 1) ans.pb(t[n / 2]);
    reverse(all(ans));

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}