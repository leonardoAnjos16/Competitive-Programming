#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        ll N, M; scanf("%lld %lld", &N, &M);
        
        ll X = 0;
        while (X < M && (X * X) % M != N) X++;
        
        if (X >= M) printf("-1\n");
        else printf("%d\n", X);
    }
}