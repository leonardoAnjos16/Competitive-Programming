#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

const int MAX = 101;

vector<vi> factors(MAX);

void get_factors() {
    vector<int> primes(MAX, 0);
    for (int i = 2; i < MAX; i++) {
        int n = i;
        for (int j = 2; j * j <= n; j++) {
            while (n % j == 0) {
                primes[j]++;
                n /= j;
            }
        }

        if (n > 1) primes[n]++;
        factors[i] = primes;
    }
}

vector<int> get_prime_factors(int N) {
    vector<int> prime_factors;
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            prime_factors.push_back(i);
            N /= i;
        }
    }

    if (N > 1) prime_factors.push_back(N);
    return prime_factors;
}

int main() {
    get_factors();
    factors[0].assign(MAX, 0);
    factors[1].assign(MAX, 0);

    int N, D;
    while (scanf("%d %d", &N, &D), N || D) {
        if (D < 0) D = -D;

        vector<int> N_factors = factors[N];
        vector<int> D_factors = get_prime_factors(D);

        int divisible = true;
        for (int i = 0; i < (int) D_factors.size() && divisible; i++) {
            if (D_factors[i] < MAX && N_factors[D_factors[i]]) N_factors[D_factors[i]]--;
            else divisible = false;
        }

        long long int num_div = 0;
        if (divisible) {
            num_div = 1;
            for (int i = 0; i < MAX; i++)
                num_div *= (N_factors[i] + 1);
        }

        printf("%lld\n", num_div);
    }
}