#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 101
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        char ruby[MAX];
        scanf("%s", ruby);
        
        int counter[4];
        for (int i = 0; i < 4; i++) counter[i] = 0;
        
        int size = strlen(ruby);
        for (int i = 0; i < size; i++) {
            if (ruby[i] == 'r') counter[0]++;
            else if (ruby[i] == 'u') counter[1]++;
            else if (ruby[i] == 'b') counter[2]++;
            else if (ruby[i] == 'y') counter[3]++;
        }
        
        int min = -1;
        for (int i = 0; i < 4; i++) {
            if (min == -1 || counter[i] < min) min = counter[i];
        }
        
        printf("%d\n", min);
    }
}