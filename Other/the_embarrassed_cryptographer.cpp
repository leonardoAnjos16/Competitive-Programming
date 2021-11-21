#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define long long long int

const int MAX = 1e6 + 5;

string K;

bool div(const int p) {
    int mod = 0LL;
    for (int i = 0, size = K.size(); i < size; i++)
        mod = (mod * 10 + K[i] - '0') % p;

    return !mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<MAX> is_prime;
    is_prime.set();

    vector<int> primes(1, 2);
    for (int i = 3; i < MAX; i += 2) {
        if (is_prime[i]) primes.push_back(i);
        for (int j = 1; j < (int) primes.size() && i * primes[j] < MAX; j++) {
            is_prime[i * primes[j]] = false;
            if (!(i % primes[j])) break;
        }
    }

    int L;
    while (cin >> K >> L, L) {
        int prime = -1;
        for (int i = 0, size = (int) primes.size(); i < size && primes[i] < L; i++)
            if (div(primes[i])) {
                prime = primes[i];
                break;
            }

        if (prime == -1) cout << "GOOD\n";
        else cout << "BAD " << prime << "\n";
    }
}