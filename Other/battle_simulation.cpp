#include <bits/stdc++.h>

using namespace std;

#define long long long int

char counter(char c) {
    if (c == 'R') return 'S';
    if (c == 'B') return 'K';
    return 'H';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    int idx = 0;
    while (idx < n) {
        if (idx + 2 < n && s[idx] != s[idx + 1] && s[idx] != s[idx + 2] && s[idx + 1] != s[idx + 2]) cout << "C", idx += 3;
        else cout << counter(s[idx++]);
    }

    cout << "\n";
}