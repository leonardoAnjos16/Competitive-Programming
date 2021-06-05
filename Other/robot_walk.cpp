#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    string s; cin >> s;

    int m; cin >> m;
    string t; cin >> t;

    cout << s[--x];
    for (char c: t) {
        x += c == 'R' ? 1 : -1;
        cout << s[x];
    }

    cout << "\n";
}