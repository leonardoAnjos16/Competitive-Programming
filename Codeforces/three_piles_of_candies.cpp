#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        long ans = (a + b + c) / 2;
        printf("%lld\n", ans);
    }
}