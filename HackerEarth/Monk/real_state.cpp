#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10000
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int num_roads;
        scanf("%d", &num_roads);
        
        bool counted[MAX];
        for (int i = 0; i < MAX; i++)
            counted[i] = false;
        
        int num_cities = 0;
        for (int i = 0; i < num_roads; i++) {
            int city_1, city_2;
            scanf("%d %d", &city_1, &city_2);
            
            if (!counted[city_1 - 1]) {
                counted[city_1 - 1] = true;
                num_cities++;
            }
            
            if (!counted[city_2 - 1]) {
                counted[city_2 - 1] = true;
                num_cities++;
            }
        }
        
        printf("%d\n", num_cities);
    }
}