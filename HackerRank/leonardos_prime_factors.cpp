#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e2;

vector<int> primes;

void get_primes() {
    bitset<MAX> is_prime;
    is_prime.set();

    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i <= MAX; i++)
        if (is_prime[i]) primes.push_back(i);
}

int main() {
    int q; scanf("%d", &q);
    get_primes();

    while (q--) {
        long long int n;
        scanf("%lld", &n);

        int max_unique = 0;
        long long int mult = 1;

        while (max_unique < 16 && mult <= n)
            mult *= primes[max_unique++];

        printf("%d\n", max_unique - 1);
    }
}