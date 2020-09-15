#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1005
 
int main() {
    int size; scanf("%d", &size);
    
    int chocolates[MAX][MAX];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &chocolates[i][j]);
            
    int max_chocolates[MAX][MAX];
    for (int i = 0; i < size; i++)
        max_chocolates[i][0] = 0;
        
    for (int i = 1; i <= size; i++)
        max_chocolates[size - 1][i] = chocolates[size - 1][i - 1];
        
    for (int i = size - 2; i >= 0; i--) {
        for (int j = 1; j < size; j++) {
            max_chocolates[i][j] = max(max_chocolates[i + 1][j - 1], max(max_chocolates[i + 1][j], max_chocolates[i + 1][j + 1]));
            max_chocolates[i][j] += chocolates[i][j - 1];
        }
        
        max_chocolates[i][size] = max(max_chocolates[i + 1][size - 1], max_chocolates[i + 1][size]);
        max_chocolates[i][size] += chocolates[i][size - 1];
    }
    
    int best = INT_MIN;
    for (int i = 1; i <= size; i++)
        best = max(best, max_chocolates[0][i]);
    
    printf("%d\n", best);
}