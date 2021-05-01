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

    int n;
    while (cin >> n, n) {
        vi factors;
        int aux = abs(n);

        for (long i = 2; i * i <= aux; i++)
            while (!(aux % i)) factors.pb(i), aux /= i;

        if (aux > 1) factors.pb(aux);

        cout << n << " = ";
        if (n < 0) cout << "-1 x ";

        for (int i = 0; i < size(factors); i++) {
            if (i) cout << " x ";
            cout << factors[i];
        }

        cout << "\n";
    }
}