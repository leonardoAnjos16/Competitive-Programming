#include <bits/stdc++.h>

using namespace std;

vector<int> get_prime_factors(int n) {
    vector<int> prime_factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            prime_factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1) prime_factors.push_back(n);
    return prime_factors;
}

int main() {
    int N; scanf("%d", &N);
    vector<int> primes = get_prime_factors(N);

    int sum_primes_digits = 0;
    for (int i = 0; i < (int) primes.size(); i++) {
        while (primes[i]) {
            sum_primes_digits += primes[i] % 10;
            primes[i] /= 10;
        }
    }

    int sum_digits = 0;
    while (N) {
        sum_digits += N % 10;
        N /= 10;
    }

    printf("%d\n", sum_primes_digits == sum_digits);
}
