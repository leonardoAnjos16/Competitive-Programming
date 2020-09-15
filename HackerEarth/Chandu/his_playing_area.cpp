#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        long long num_straws;
        scanf("%lld", &num_straws);
        
        long long first_side = num_straws / 4;
        long long area = first_side * ((num_straws / 2) - first_side);
        printf("%lld\n", area);
    }
}