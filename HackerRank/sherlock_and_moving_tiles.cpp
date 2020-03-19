#include <bits/stdc++.h>

using namespace std;

int main() {
    int L, S1, S2;
    scanf("%d %d %d", &L, &S1, &S2);

    int Q; scanf("%d", &Q);

    double sqrt_two = sqrt(2);
    int v = abs(S2 - S1);

    while (Q--) {
        long long int q; scanf("%lld", &q);
        double time = sqrt_two * (L - sqrt(q)) / v;
        printf("%lf\n", time);
    }
}