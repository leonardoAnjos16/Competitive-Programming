#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1005
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int size, D;
        scanf("%d %d", &size, &D);
        
        int numbers[MAX];
        for (int i = 0; i < size; i++)
            scanf("%d", &numbers[i]);
            
        bool okay = true;
        for (int i = 1; i < size && okay; i++)
            if (abs(numbers[i] - numbers[i - 1]) > D)
                okay = false;
                
        printf("%s\n", okay ? "YES" : "NO");
    }
}