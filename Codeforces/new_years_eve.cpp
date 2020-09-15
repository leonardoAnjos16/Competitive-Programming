#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    long n, k;
    scanf("%lld %lld", &n, &k);

    int exp = 0;
    while ((1LL << ++exp) <= n);

    long ans = k == 1 ? n : (1LL << exp) - 1;
    printf("%lld\n", ans);
}