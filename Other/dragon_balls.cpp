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

const int MAX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while (n--) {
        cout << "0 0\n";
        cout.flush();

        long d; cin >> d;
        if (!d) continue;

        bool found = false;
        for (long x = 0LL; x * x <= d && x <= MAX && !found; x++) {
            long y = sqrt(d - x * x);
            
            if (y > MAX) continue;
            if (x * x + y * y != d) continue;

            cout << x << " " << y << "\n";
            cout.flush();

            long nd; cin >> nd;
            if (!nd) found = true;
        }
    }
}