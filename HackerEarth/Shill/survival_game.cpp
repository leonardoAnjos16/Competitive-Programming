#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100005
 
int main() {
    int num_comrades;
    scanf("%d", &num_comrades);
    
    int comrades[MAX];
    for (int i = 0; i < num_comrades; i++)
        scanf("%d", &comrades[i]);
        
    int left[MAX], right[MAX];
    left[0] = comrades[0]; right[num_comrades - 1] = comrades[num_comrades - 1];
    
    for (int i = 1; i < num_comrades; i++) {
        left[i] = max(comrades[i], left[i - 1]);
        right[num_comrades - i - 1] = max(comrades[num_comrades - i - 1], right[num_comrades - i]);
    }
    
    vector<int> winners;
    for (int i = 0; i < num_comrades; i++)
        if (left[i] == comrades[i] || right[i] == comrades[i])
            winners.push_back(i + 1);
            
    for (int i = 0; i < (int) winners.size(); i++)
        printf("%d ", winners[i]);
}