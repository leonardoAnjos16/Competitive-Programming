#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long int fact_mod(long long int n) {
    if (n == 0) return 1;
    else return (n * fact_mod(n - 1)) % MOD;
}

long long int pow_mod(long long int base, int exp) {
    if (exp == 0) return 1;
    else if (exp % 2) return (base * pow_mod(base, exp - 1)) % MOD;
    else {
        long long int aux = pow_mod(base, exp / 2);
        return (aux * aux) % MOD;
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        long long int m, n;
        scanf("%lld %lld", &m, &n);

        long long int a = m + n - 2;
        long long int answer = 1;

        for (int i = 0; i < n - 1; i++)
            answer = (answer * (a - i)) % MOD;

        answer = (answer * pow_mod(fact_mod(n - 1), MOD - 2)) % MOD;

        printf("%lld\n", answer);
    }
}