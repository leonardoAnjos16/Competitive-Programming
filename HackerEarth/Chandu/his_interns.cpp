#include <bits/stdc++.h>
 
using namespace std;
 
bool divisors(int number) {
    double square_root = sqrt(number);
    for (int i = 2; i <= square_root; i++) {
        if (number % i == 0 && i != square_root)
            return false;
    }
    
    return true;
}
 
int main() {
    int num_bottles;
    scanf("%d", &num_bottles);
    
    while (num_bottles--) {
        int number;
        scanf("%d", &number);
        
        if (divisors(number)) printf("NO\n");
        else printf("YES\n");
    }
}