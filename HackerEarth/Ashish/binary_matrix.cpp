#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int num_rows, num_cols;
        scanf("%d %d", &num_rows, &num_cols);
        
        vector<string> rows(num_rows);
        for (int i = 0; i < num_rows; i++)
            cin >> rows[i];
            
        bool possible = false;
        for (int i = 0; i < num_cols && !possible; i++) {
            set<string> unique_rows;
            bool impossible = false;
            
            for (int j = 0; j < num_rows && !impossible; j++) {
                string row = rows[j].substr(0, i) + rows[j].substr(i + 1, num_cols);
                if (unique_rows.find(row) != unique_rows.end()) impossible = true;
                else unique_rows.insert(row);
            }
            
            if (unique_rows.size() == num_rows) possible = true;
        }
        
        printf("%s\n", possible ? "Yes" : "No");
    }
}