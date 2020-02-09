#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long int ll;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        ll P, M; scanf("%lld %lld", &P, &M);
        ll P_xor_M = P ^ M;
        
        int num_diff = 0;
        for (int j = 0; j < 64; j++)
            if (P_xor_M & (1L << j))
                num_diff++;
                
        printf("%d\n", num_diff);
    }
}