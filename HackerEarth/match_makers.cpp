#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int num_couples;
        scanf("%d", &num_couples);
        
        vector<int> girls(num_couples), boys(num_couples);
        for (int i = 0; i < num_couples; i++)
            scanf("%d", &girls[i]);
            
        for (int i = 0; i < num_couples; i++)
            scanf("%d", &boys[i]);
            
        sort(girls.begin(), girls.end());
        sort(boys.rbegin(), boys.rend());
        
        int num_ideal_pairs = 0;
        for (int i = 0; i < num_couples; i++)
            if (girls[i] % boys[i] == 0 || boys[i] % girls[i] == 0)
                num_ideal_pairs++;
                
        printf("%d\n", num_ideal_pairs);
    }
}