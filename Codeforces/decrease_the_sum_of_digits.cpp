#include <bits/stdc++.h>

using namespace std;

#define long long long int

int digits_sum(long n) {
    int sum = 0;
    while (n) {
        sum += n % 10LL;
        n /= 10LL;
    }

    return sum;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long n; int s;
        scanf("%lld %d", &n, &s);

        long ans = 0, power = 1;
        while (digits_sum(n) > s) {
            long next = n + (power * 10);
            next -= next % (power * 10);

            long diff = next - n;
            ans += diff;

            n = next;
            while (!(n % (power * 10)))
                power *= 10;
        }

        printf("%lld\n", ans);
    }
}