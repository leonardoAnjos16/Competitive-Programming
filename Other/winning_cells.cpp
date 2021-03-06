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

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("chess.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        long n, k;
        cin >> n >> k;

        long bad = (k + 1) * (n / (k + 1)) * (n / (k + 1));
        bad += 2 * (n % (k + 1)) * (n / (k + 1));
        bad += n % (k + 1);

        long ans = n * n - bad;
        cout << ans << "\n";
    }
}