#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
 
int main() {
    int num_rows, num_cols;
    scanf("%d %d", &num_rows, &num_cols);
    
    map<int, ii> positions;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            int number; scanf("%d", &number);
            positions[number] = {i, j};
        }
    }
    
    int num_queries;
    scanf("%d", &num_queries);
    
    while (num_queries--) {
        int number; scanf("%d", &number);
        map<int, ii>::iterator position = positions.find(number);
        
        int row = -1, col = -1;
        if (position != positions.end()) {
            row = position->second.first;
            col = position->second.second;
        }
        
        printf("%d %d\n", row, col);
    }
}