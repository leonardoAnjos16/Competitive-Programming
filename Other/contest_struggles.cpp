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

    cout << setprecision(8) << fixed;

    int n, k;
    cin >> n >> k;

    int d, s;
    cin >> d >> s;

    int aux = d * n - s * k;
    double ans = (aux + .0) / (n - k);

    if (ans < 0.0 || ans > 100.0) cout << "impossible\n";
    else cout << ans << "\n";
}