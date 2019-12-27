#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        ll heights[3];
        for (int i = 0; i < 3; i++)
            scanf("%lld", &heights[i]);
        
        ll moves = heights[1] - heights[0];
        if (heights[2] - heights[1] > moves) moves = heights[2] - heights[1];
        
        printf("%lld\n", --moves);
    }
}