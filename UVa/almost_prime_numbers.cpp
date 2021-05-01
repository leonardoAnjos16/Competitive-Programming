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

    for (long i = 3LL; i * i < MAX; i += 2LL)
        if (prime[i])
            for (long j = i * i; j < MAX; j += i)
                prime[j] = false;

    vector<long> primes;
    primes.pb(2LL);

    for (int i = 3; i < MAX; i += 2)
        if (prime[i]) primes.pb(i);;

    int N; cin >> N;
    while (N--) {
        long low, high;
        cin >> low >> high;

        long ans = 0LL;
        for (auto p: primes) {
            long pow = p * p;
            while (pow < low) pow *= p;
            while (pow <= high) ans++, pow *= p;
        }

        cout << ans << "\n";
    }
}