#include <bits/stdc++.h>

using namespace std;

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

    cout << setprecision(8) << fixed;

    long double a; long long int b, c;
    cin >> a >> b >> c;

    if (a <= 1.0) {
        long double ans = log2(1 + c * b);
        cout << ans << "\n";
    } else {
        long long int q = floor((b - a + 1) / (b * (a - 1))) + 1;
        q = min(q, c); c -= q;

        long double ans = c * log2(a) + log2(1 + q * b);
        cout << ans << "\n";
    }
}