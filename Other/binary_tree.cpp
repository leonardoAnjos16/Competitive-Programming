#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
        }
        
        cout << ((n & 1) ? "Alice" : "Bob") << "\n";
    }
}