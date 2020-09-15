#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int size, num_removed, P;
        scanf("%d %d %d", &size, &num_removed, &P);
        
        int removed;
        while (num_removed--) {
            scanf("%d", &removed);
            if (removed <= P) P++;
        }
        
        if (P > size) printf("-1\n");
        else printf("%d\n", P);
    }
}