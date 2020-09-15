#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int Q; scanf("%d", &Q);
    while (Q--) {
        int N; scanf("%d", &N);

        long ans = N * (N - 1LL) + 1LL;
        printf("%lld\n", ans);
    }
}