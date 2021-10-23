#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string S; cin >> S;

        int hor = 0, ver = 0;
        for (char c: S) {
            if (c == 'L') hor--;
            else if (c == 'R') hor++;
            else if (c == 'D') ver--;
            else ver++;
        }

        hor = abs(hor);
        ver = abs(ver);

        int ans = 0;
        if (hor & 1) ans++, hor--;
        if (ver & 1) ans++, ver--;

        ans += hor >> 1;
        ans += ver >> 1;

        cout << ans << "\n";
    }
}