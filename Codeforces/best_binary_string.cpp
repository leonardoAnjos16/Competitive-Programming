#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        char last = '0';
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '?') s[i] = last;
            last = s[i];
        }

        cout << s << "\n";
    }
}