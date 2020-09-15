#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int n; long k;
    scanf("%d %lld", &n, &k);

    int cnt = 0;
    long init = 0;

    do init = 1LL << cnt;
    while (++cnt <= n && (k - init) % (1LL << cnt));

    printf("%d\n", cnt);
}