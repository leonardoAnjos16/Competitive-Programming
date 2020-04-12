#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e6 + 1;

vector<long> T_primes;

void get_T_primes() {
    bitset<MAX> is_prime;
    is_prime.set();

    for (int i = 2; i * i < MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
    }

    for (long i = 2; i < MAX; i++)
        if (is_prime[i]) T_primes.push_back(i * i);
}

int main() {
    int n; scanf("%d", &n);
    get_T_primes();

    while (n--) {
        long x; scanf("%lld", &x);
        printf("%s\n", binary_search(T_primes.begin(), T_primes.end(), x) ? "YES" : "NO");
    }
}