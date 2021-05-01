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

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vi indices[MAX];
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            indices[a].pb(i);
        }

        int ans;
        for (int i = 0; i < MAX; i++)
            if (size(indices[i]) == 1)
                ans = indices[i][0] + 1;

        cout << ans << "\n";
    }
}