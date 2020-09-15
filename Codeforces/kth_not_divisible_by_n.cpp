#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long n, k; scanf("%lld %lld", &n, &k);

        long aux = --k / (n - 1);
        long ans = (n * aux) + (k % (n - 1)) + 1;

        printf("%lld\n", ans);
    }
}