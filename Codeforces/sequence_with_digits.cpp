#include <bits/stdc++.h>

using namespace std;

#define long long long int
#define pair pair<int, int>
#define mn first
#define mx second

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long a, K; scanf("%lld %lld", &a, &K);

        pair digits = {INT_MAX, INT_MIN};
        while (--K && digits.mn > 0) {
            digits = {INT_MAX, INT_MIN};

            long aux = a;
            while (aux) {
                digits.mn = min((long) digits.mn, aux % 10LL);
                digits.mx = max((long) digits.mx, aux % 10LL);
                aux /= 10LL;
            }

            a += digits.mn * digits.mx;
        }

        printf("%lld\n", a);
    }
}