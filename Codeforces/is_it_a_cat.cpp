#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        if (s[0] >= 'A' && s[0] <= 'Z') s[0] = s[0] - 'A' + 'a';
        bool cat = (s[0] == 'm');

        for (int i = 1; i < n && cat; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';

            if (s[i] == 'm') cat &= (s[i - 1] == 'm');
            else if (s[i] == 'e') cat &= (s[i - 1] == 'm') || (s[i - 1] == 'e');
            else if (s[i] == 'o') cat &= (s[i - 1] == 'e') || (s[i - 1] == 'o');
            else if (s[i] == 'w') cat &= (s[i - 1] == 'o') || (s[i - 1] == 'w');
            else cat = false;
        }

        cat &= s.back() == 'w';
        cout << (cat ? "YES" : "NO") << "\n";
    }
}