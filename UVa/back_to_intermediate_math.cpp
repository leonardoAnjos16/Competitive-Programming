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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(3) << fixed;

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        double d, v, u;
        cin >> d >> v >> u;

        cout << "Case " << t << ": ";
        if (!u || !v || v >= u) cout << "can't determine\n";
        else {
            double t1 = d / u;
            double t2 = d / sqrt(u * u - v * v);

            double ans = t2 - t1;
            cout << ans << "\n";
        }
    }
}