#include <bits/stdc++.h>
 
using namespace std;
 
#define long long long int
 
int main() {
    int Q; scanf("%d", &Q);
    while (Q--) {
        long N; int T;
        scanf("%lld %d", &N, &T);
 
        while (T--) {
            if (N % 2 == 0) N /= 2;
            else N -= (N + 1) / 2;
 
            N -= N / 4;
        }
 
        printf("%lld\n", N);
    }
}