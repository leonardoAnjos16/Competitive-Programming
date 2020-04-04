#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    long long int ans = n % 2 ? 0 : (1L << (n / 2));
    printf("%lld\n", ans);
}