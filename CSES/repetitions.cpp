#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    int n = s.size();
    s += '-';
    
    int cnt = 1, ans = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[i - 1]) cnt++;
        else ans = max(ans, cnt), cnt = 1;
    }
    
    cout << ans << "\n";
}