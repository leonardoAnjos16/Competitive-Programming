#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define MAX 9876543210

bool are_all_diff(ll number) {
    char digits[20]; sprintf(digits, "%lld", number);
    int num_digits = strlen(digits);

    int aux = 0;
    for (int i = 0; i < num_digits; i++) {
        int digit = digits[i] - '0';
        if (aux & (1 << digit)) return false;
        aux |= (1 << digit);
    }

    return true;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        ll number; scanf("%lld", &number);
        
        ll numerator = number, denominator = 1;
        while (numerator <= MAX) {
            bool all_diff = are_all_diff(numerator);
            if (all_diff) printf("%lld / %lld = %lld\n", numerator, denominator, number);

            while (++denominator <= MAX && !are_all_diff(denominator));
            numerator = number * denominator;
        }

        if (num_cases) printf("\n");
    }
}