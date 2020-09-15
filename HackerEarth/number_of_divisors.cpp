#include <bits/stdc++.h>
 
using namespace std;
 
int get_num_divisors(long long int N) {
    int square_root = (int) sqrt(N);
    int num_divisors = 2;
    
    for (int i = 2; i <= square_root; i++)
        if (N % i == 0) num_divisors += 2;
        
    if (sqrt(N) == (double) square_root) num_divisors--;
    return num_divisors;
}
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        long long int N; scanf("%lld", &N);
        printf("%d\n", get_num_divisors(N));
    }
}