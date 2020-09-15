#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    
    long long int coins = 0, zero = 0;
    bool pos = true;

    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);

        if (a < 0) coins += -1L - a, pos = !pos;
        else if (a > 0) coins += a - 1L;
        else zero++;
    }

    if (zero > 0) coins += zero;
    else if (!pos) coins += 2L;

    printf("%lld\n", coins);
}