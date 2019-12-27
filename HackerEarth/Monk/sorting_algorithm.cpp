#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000000
#define REMAINDER 100000
 
typedef long long int ll;
 
int main() {
    int size;
    scanf("%d", &size);
    
    ll numbers[MAX];
    for (int i = 0; i < size; i++)
        scanf("%lld", &numbers[i]);
        
    bool all_zero = false;
    ll divisor = 1;
    
    while (!all_zero) {
        all_zero = true;
        divisor *= 100000;
        
        vector<ll> remainders[REMAINDER];
        ll last_divisor = divisor / 100000;
        
        for (int i = 0; i < size; i++) {
            ll digits = (numbers[i] % divisor) / last_divisor;
            remainders[digits].push_back(numbers[i]);
            all_zero &= (digits == 0);
        }
        
        if (!all_zero) {
            int counter = 0;
            for (int i = 0; i < REMAINDER; i++) {
                for (int j = 0; j < remainders[i].size(); j++)
                    numbers[counter++] = remainders[i][j];
            }
            
            for (int i = 0; i < size; i++)
                printf("%lld ", numbers[i]);
                
            printf("\n");
        }
    }
}