#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int already_there, yet_to_come;
        scanf("%d %d", &already_there, &yet_to_come);
        
        int num_students = already_there + yet_to_come;
        map<ll, bool> candies;
        
        for (int i = 0; i < num_students; i++) {
            ll candie;
            scanf("%lld", &candie);
            
            if (i >= already_there && candies.count(candie) == 1) {
                printf("YES\n");
            } else if (i >= already_there) {
                printf("NO\n");
            }
            
            candies[candie] = true;
        }
    }
}