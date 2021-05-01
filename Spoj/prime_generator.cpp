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

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<MAX> prime;
    prime.set();

    for (int i = 3; i * i < MAX; i += 2)
        if (prime[i])
            for (int j = i * i; j < MAX; j += i)
                prime[j] = false;

    vector<long> primes;
    primes.pb(2LL);

    for (int i = 3; i < MAX; i += 2)
        if (prime[i]) primes.pb(i);

    int t; cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;

        prime.set();
        for (auto p: primes) {
            long s = p * p;
            if (s < m)
                s = p * ((m - 1) / p + 1);

            for (long i = s; i <= n; i += p)
                prime[i - m] = false;
        }

        for (int i = m; i <= n; i++)
            if (i > 1 && prime[i - m]) cout << i << "\n";

        if (t) cout << "\n";
    }
}