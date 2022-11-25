#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        string ans = s;
        reverse(s.begin(), s.end());
        ans += s;

        cout << ans << "\n";
    }
}