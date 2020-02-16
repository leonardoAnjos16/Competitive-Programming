#include <bits/stdc++.h>

using namespace std;

#define MAX 25

int main() {
    int n; scanf("%d", &n);
    
    int crackers[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &crackers[i]);
        
    set<int> money;
    int subset = 0;
    
    while (++subset < (1 << n)) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (subset & (1 << i))
                sum += crackers[i];
                
        if (sum % 2 == 0) money.insert(sum / 2);
    }
    
    printf("%d\n", (int) money.size());
}