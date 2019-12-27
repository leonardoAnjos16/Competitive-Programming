#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100001
 
typedef long long int long_int;
 
int main() {
    int num_mountains, num_queries;
    scanf("%d %d", &num_mountains, &num_queries);
    
    long_int bases[MAX], prefix_sum[MAX];
    prefix_sum[0] = 0;
    
    for (int i = 0; i < num_mountains; i++) {
        long_int base, top;
        scanf("%lld %lld", &base, &top);
        
        bases[i] = base;
        prefix_sum[i + 1] = prefix_sum[i] + (top - base + 1);
    }
    
    for (int i = 0; i < num_queries; i++) {
        long_int x;
        scanf("%lld", &x);
        
        long_int index = lower_bound(prefix_sum, prefix_sum + num_mountains + 1, x) - prefix_sum;
        
        x -= prefix_sum[index - 1];
        long_int height = bases[index - 1] + x - 1;
        printf("%lld\n", height);
    }
}