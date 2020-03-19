#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        long long int n;
        scanf("%lld", &n);

        n %= MOD;
        n *= n;

        printf("%lld\n", n % MOD);
    }
}