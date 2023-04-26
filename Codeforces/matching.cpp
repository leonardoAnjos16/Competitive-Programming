#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        if (s[0] == '0') cout << "0\n";
        else {
            int ans = 1;
            for (int i = 0; i < (int) s.size(); i++)
                if (s[i] == '?') {
                    if (!i) ans *= 9;
                    else ans *= 10;
                }

            cout << ans << "\n";
        }
    }
}