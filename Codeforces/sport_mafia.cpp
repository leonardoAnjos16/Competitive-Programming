#include <bits/stdc++.h>

using namespace std;

int main() {
    #define int long long int
    int n, k; scanf("%lld %lld", &n, &k);

    int l = 0, r = n - 1, taken;
    while (l <= r) {
        taken = (l + r) / 2;

        int put = n - taken;
        put = put * (put + 1) / 2;

        if (put - taken == k) break;
        else if (put - taken > k) l = taken + 1;
        else r = taken - 1;
    }

    printf("%lld\n", taken);
}