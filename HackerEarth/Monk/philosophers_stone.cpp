#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10000
 
int main() {
    int size;
    scanf("%d", &size);
    
    int coins[MAX];
    for (int i = 0; i < size; i++)
        scanf("%d", &coins[i]);
        
    int num_queries, target_sum;
    scanf("%d %d", &num_queries, &target_sum);
    
    stack<int> monk_bag;
    int curr_sum = 0, target_size = -1, index = -1;
    bool done = false;
    
    for (int i = 0; i < num_queries; i++) {
        char input[10];
        scanf("%s", input);
        
        if (input[0] == 'H') {
            monk_bag.push(coins[++index]);
            curr_sum += coins[index];
        } else {
            curr_sum -= monk_bag.top();
            monk_bag.pop();
        }
        
        if (!done && curr_sum == target_sum) {
            target_size = monk_bag.size();
            done = true;
        }
    }
    
    printf("%d\n", target_size);
}