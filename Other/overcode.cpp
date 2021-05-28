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

const int MAX = 505;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("overcode.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        int r[MAX];
        for (int i = 0; i < n; i++)
            cin >> r[i];

        sort(r, r + n);

        int ans = 0, idx = 0;
        while (idx + 5 < n) {
            if (r[idx + 5] - r[idx] > 1000) idx++;
            else ans++, idx += 6;
        }

        cout << ans << "\n";
    }
}