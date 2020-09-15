#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int num_touches;
        scanf("%d", &num_touches);
        
        long long int num_zero = 0, num_one = 1;
        while (num_touches--) {
            long long int aux = num_zero;
            num_zero += num_one;
            num_one = aux;
        }
        
        printf("%lld %lld\n", num_one, num_zero);
    }
}