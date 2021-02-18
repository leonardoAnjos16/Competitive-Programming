#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int N, K, S;
        cin >> N >> K >> S;
        
        int ans = (K - S) + (N - S);
        ans = min(ans, N) + K;
        
        cout << "Case #" << i << ": " << ans << "\n";
    }
}