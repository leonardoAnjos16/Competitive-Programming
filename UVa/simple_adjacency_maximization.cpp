#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int C; scanf("%d", &C);
    while (C--) {
        int P, Q; scanf("%d %d", &P, &Q);

        long ans = 0LL;
        int pat = min(P >> 1, Q);

        for (int i = 0; i < pat; i++)
            ans = (ans << 3LL) | 5LL;

        P -= pat << 1;
        Q -= pat;

        if (!Q) while (P--) ans = (ans << 1LL) | 1LL;
        else if (P) {
            long aux = ans; int cnt = 0;
            while (aux) aux >>= 1LL, cnt++;
            ans = (1LL << cnt) | ans;
        }

        printf("%lld\n", ans);
    }
}