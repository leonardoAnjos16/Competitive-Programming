#include <bits/stdc++.h>
 
using namespace std;
 
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
 
bool is_prime(int number) {
    if (number == 1) return false;
    
    double square_root = sqrt(number);
    for (int i = 2; i <= square_root; i++)
        if (number % i == 0) return false;
        
    return true;
}
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int number;
        scanf("%d", &number);
        
        int counter = 0;
        for (int i = 1; i <= number; i++)
            if (gcd(number, i) == 1) counter++;
            
        if (is_prime(counter)) printf("TRUE\n");
        else printf("FALSE\n");
    }
}