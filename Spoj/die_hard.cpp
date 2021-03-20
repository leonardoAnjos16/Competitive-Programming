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

const int MAX = 1e3 + 5;

int memo[MAX][MAX][3];

int time(int H, int A, int place) {
    if (H <= 0 || A <= 0) return 0;

    int &ans = memo[H][A][place];
    if (~ans) return ans;

    if (place != 0) ans = max(ans, time(H + 3, A + 2, 0));
    if (place != 1) ans = max(ans, time(H - 5, A - 10, 1));
    if (place != 2) ans = max(ans, time(H - 20, A + 5, 2));

    return ++ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int H, A;
        cin >> H >> A;

        memset(memo, -1, sizeof memo);

        int ans = INT_MIN;
        ans = max(ans, time(H + 3, A + 2, 0));
        ans = max(ans, time(H - 5, A - 10, 1));
        ans = max(ans, time(H - 20, A + 5, 2));

        cout << ans << "\n";
    }
}