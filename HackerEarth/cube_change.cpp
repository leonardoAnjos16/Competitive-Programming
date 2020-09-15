#include <bits/stdc++.h>
 
using namespace std;
 
#define long long long int
 
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        long N; scanf("%lld", &N);
 
        long total_vol = N * N * N;
        if (N > 2) total_vol -= (N - 2) * (N - 2) * (N - 2);
 
        printf("%lld\n", total_vol);
    }
}