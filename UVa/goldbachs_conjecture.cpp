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

    vi primes;
    for (long i = 2; i < MAX; i++) {
        if (prime[i]) {
            primes.pb(i);
            for (long j = i * i; j < MAX; j += i)
                prime[j] = false;
        }
    }

    int n;
    while (cin >> n, n) {
        int a = -1, b = -1;
        for (int i = 0; i < size(primes) && primes[i] <= n / 2 && a == -1; i++) {
            bool found = binary_search(all(primes), n - primes[i]);
            if (found) a = primes[i], b = n - primes[i];
        }

        cout << n << " = " << a << " + " << b << "\n";
    }
}