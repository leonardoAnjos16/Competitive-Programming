#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int number; scanf("%d", &number);
        if (number % 21 == 0) printf("The streak is broken!\n");
        else {
            int last = 0;
            bool okay = true;
            
            while (number && okay) {
                int digit = number % 10;
                if (last == 1 && digit == 2) okay = false;
                
                last = digit;
                number /= 10;
            }
            
            if (okay) printf("The streak lives still in our heart!\n");
            else printf("The streak is broken!\n");
        }
    }
}