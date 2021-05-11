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

    long n, q;
    cin >> n >> q;

    while (q--) {
        long x, y;
        cin >> x >> y;

        long ceils = x / 2, floors = (x - 1) / 2;
        if ((x + y) & 1) swap(ceils, floors);

        long aux = ceils * ((n + 1) / 2) + floors * (n / 2);
        aux += (y - 1) / 2;

        long first = 1;
        if ((x + y) & 1)
            first = (n * n + 1) / 2 + 1;

        long ans = first + aux;
        cout << ans << "\n";
    }
}