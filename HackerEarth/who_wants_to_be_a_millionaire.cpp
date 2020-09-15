#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int num_doors;
        scanf("%d", &num_doors);
        
        double prob = ((double) (num_doors - 1)) / num_doors;
        printf("%.6f\n", prob);
    }
}