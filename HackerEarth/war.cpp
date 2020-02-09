#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int size; scanf("%d", &size);
        
        int bob = INT_MIN, alice = INT_MIN, soldier;
        for (int i = 0; i < size; i++) {
            scanf("%d", &soldier);
            if (soldier > bob) bob = soldier;
        }
            
        for (int i = 0; i < size; i++) {
            scanf("%d", &soldier);
            if (soldier > alice) alice = soldier;
        }
            
        if (bob == alice) printf("Tie\n");
        else if (bob > alice) printf("Bob\n");
        else printf("Alice\n");
    }
}