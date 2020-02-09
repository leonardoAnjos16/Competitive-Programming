#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll pow(ll base, int exp) {
    if (exp == 0) return 1;
    else return base * pow(base, exp - 1);
}

#define MAX 25

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int degree; scanf("%d", &degree);

        int coefs[MAX];
        for (int i = 0; i <= degree; i++)
            scanf("%d", &coefs[i]);

        int d, k; scanf("%d %d", &d, &k);

        ll n = 0, sum = 0;
        while (sum < k) sum += (++n * d);

        ll number = coefs[0];
        for (int i = 1; i <= degree; i++)
            number += coefs[i] * pow(n, i);

        printf("%lld\n", number);
    }
}