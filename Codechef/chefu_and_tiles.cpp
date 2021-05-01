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

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vi primes; int aux = N;
        for (int i = 2; i * i <= aux; i++) {
            if (!(aux % i)) primes.pb(i);
            while (!(aux % i)) aux /= i;
        }

        if (aux > 1) primes.pb(aux);

        int num = 1, den = 1;
        for (auto p: primes)
            num *= (p - 1), den *= p;

        int ans = N / den * num;
        cout << ans << "\n";
    }
}