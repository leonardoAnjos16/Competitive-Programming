#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        long TS; scanf("%lld", &TS);

        long aux = TS; int cnt = 1;
        while (!(aux & 1LL)) aux >>= 1LL, cnt++;

        long ans = TS / (1LL << cnt);
        printf("%lld\n", ans);
    }
}