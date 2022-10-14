#include <iostream>
 
using namespace std;
 
const int MAX = 2e5 + 5;
 
int main() {
    int n; cin >> n;
    
    bool seen[MAX] = {0};
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        seen[a] = true;
    }
    
    int ans = -1;
    for (int i = 1; i <= n && ans == -1; i++)
        if (!seen[i]) ans = i;
        
    cout << ans << "\n";
}