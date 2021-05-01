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

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<MAX> prime;
    prime.set();

    for (long i = 2; i * i < MAX; i++)
        if (prime[i])
            for (long j = i * i; j < MAX; j += i)
                prime[j] = false;

    vi primes;
    for (int i = 2; i < MAX; i++)
        if (prime[i]) primes.pb(i);

    int L, U;
    while (cin >> L >> U) {
        prime.set();
        for (long p: primes) {
            long i = p * p;
            if (i < L) i += (L - i - 1) / p * p + p;
            while (i <= U) prime[i - L] = false, i += p;
        }

        vi range_primes;
        for (long i = L; i <= U; i++)
            if (i > 1 && prime[i - L]) range_primes.pb(i);

        if (size(range_primes) < 2) cout << "There are no adjacent primes.\n";
        else {
            int C1, C2, D1, D2;
            C1 = D1 = range_primes[0];
            C2 = D2 = range_primes[1];

            for (int i = 2; i < size(range_primes); i++) {
                if (range_primes[i] - range_primes[i - 1] < C2 - C1) C1 = range_primes[i - 1], C2 = range_primes[i];
                if (range_primes[i] - range_primes[i - 1] > D2 - D1) D1 = range_primes[i - 1], D2 = range_primes[i];
            }

            cout << C1 << "," << C2 << " are closest, " << D1 << "," << D2 << " are most distant.\n";
        }
    }
}