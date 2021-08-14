#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<int> primes;
    for (long i = 2LL; i * i <= n; i++) {
        while (!(n % i)) {
            n /= i;
            primes.push_back(i);
        }
    }

    if (n > 1) primes.push_back(n);

    bool sphenic = (int) primes.size() == 3;
    sphenic &= primes[0] != primes[1] && primes[1] != primes[2];

    cout << (sphenic ? "YES" : "NO") << "\n";
}