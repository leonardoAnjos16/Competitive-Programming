#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    char word[20];
    while (num_cases--) {
        scanf("%s", word);
        int size = strlen(word);
        
        bool palindrome = true;
        for (int i = 0; i < (size >> 1) && palindrome; i++)
            if (word[i] != word[size - i - 1])
                palindrome = false;
                
        if (palindrome) printf("Palindrome\n");
        else {
            long long int prod = 1;
            for (int i = 0; i < size; i++)
                prod *= (word[i] - 'a' + 1);
                
            printf("%lld\n", prod);
        }
    }
}