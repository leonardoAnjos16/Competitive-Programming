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

    int n; cin >> n;

    long g = 0;
    for (int i = 0; i < n; i++) {
        long a; cin >> a;
        g = gcd(g, a);
    }

    long ans = 0;
    for (long i = 1; i * i <= g; i++)
        if (!(g % i)) {
            ans += 2;
            if (i * i == g) ans--;
        }

    cout << ans << "\n";
}