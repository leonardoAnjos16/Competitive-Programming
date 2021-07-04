#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    int ans = h + (m >= 60.0 * (h % 12) / 11.0);
    if (h >= 12) ans--;
    
    cout << ans << "\n";
}