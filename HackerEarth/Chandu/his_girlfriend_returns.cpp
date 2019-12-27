#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 50000
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int sizes[2];
        scanf("%d %d", &sizes[0], &sizes[1]);
        
        int array[2][MAX];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < sizes[i]; j++)
                scanf("%d", &array[i][j]);
                
        int counters[] = { 0, 0 };
        while (counters[0] < sizes[0] && counters[1] < sizes[1]) {
            if (array[0][counters[0]] >= array[1][counters[1]])
                printf("%d ", array[0][counters[0]++]);
            else
                printf("%d ", array[1][counters[1]++]);
        }
        
        if (counters[0] < sizes[0]) {
            printf("%d", array[0][counters[0]++]);
            for (int i = counters[0]; i < sizes[0]; i++)
                printf(" %d", array[0][i]);
        } else {
            printf("%d", array[1][counters[1]++]);
            for (int i = counters[1]; i < sizes[1]; i++)
                printf(" %d", array[1][i]);
        }
        
        printf("\n");
    }
}