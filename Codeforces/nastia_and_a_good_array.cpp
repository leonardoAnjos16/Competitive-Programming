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

const int MAX_N = 1e5 + 5;
const int MAX_A = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int a[MAX_N], mn_idx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < a[mn_idx])
                mn_idx = i;
        }

        vector<tuple<int, int, int, int>> ans;
        for (int i = mn_idx + 1; i < n; i++)
            ans.pb({ mn_idx + 1, i + 1, a[mn_idx], a[mn_idx] + i - mn_idx });

        for (int i = mn_idx - 1; i >= 0; i--)
            ans.pb({ i + 1, mn_idx + 1, a[mn_idx] + mn_idx - i, a[mn_idx] });

        cout << size(ans) << "\n";
        for (auto t: ans) {
            int i, j, x, y;
            tie(i, j, x, y) = t;
            cout << i << " " << j << " " << x << " " << y << "\n";
        }
    }
}