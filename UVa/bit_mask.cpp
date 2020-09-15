#include <bits/stdc++.h>

using namespace std;

#define long long long int

int count(long n) {
    int cnt = 0;
    while (n) cnt++, n >>= 1LL;
    return cnt;
}

int main() {
    long N, L, U;
    while (scanf("%lld %lld %lld", &N, &L, &U) != EOF) {
        int idx = count(U);
        long ans = 0LL;

        while (--idx >= 0) {
            /*
            if (!(N & (1LL << idx)) && !(L & (1LL << idx)) && (ans | (1LL << idx)) <= U)
                ans |= 1LL << idx;
            else if ((N & (1LL << idx)) && (L & (1LL << idx)) && (ans ^ (1LL << idx)) >= L)
                ans ^= 1LL << idx;
            */

            if ((N & (1LL << idx)) && (ans | ((1LL << idx) - 1)) < L) ans |= 1LL << idx;
            else if (!(N & (1LL << idx)) && (ans | (1LL << idx)) <= U) ans |= 1LL << idx;
        }

        printf("%lld\n", ans);
    }
}