#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        bool zero = s[0] == '0';
        int zeroes = s[0] == '0', ones = s[0] == '1';

        for (int i = 1; i < n; i++) {
            if (!zero && s[i] == '0') zeroes++, zero = true;
            else if (zero && s[i] == '1') ones++, zero = false;
        }

        int ans = !zeroes ? 0 : (!ones ? 1 : 2);
        ans = min(ans, zeroes);
        cout << ans << "\n";
    }
}