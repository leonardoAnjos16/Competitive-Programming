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

const int MAX = 2e7 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<MAX> composite;
    for (long i = 3; i * i < MAX; i += 2)
        if (!composite[i])
            for (long j = i * i; j < MAX; j += i)
                composite[j] = true;

    vi primes;
    for (int i = 3; i < MAX; i += 2)
        if (!composite[i]) primes.pb(i);

    vector<pii> pairs;
    for (int i = 1; i < size(primes); i++)
        if (primes[i] - primes[i - 1] == 2)
            pairs.pb({ primes[i - 1], primes[i] });

    int S;
    while (cin >> S)
        cout << "(" << pairs[S - 1].fst << ", " << pairs[S - 1].snd << ")\n";
}