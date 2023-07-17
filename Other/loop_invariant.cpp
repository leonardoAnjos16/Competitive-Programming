#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    string ans = s;
    int balance = 0;
    bool done = false;

    for (int i = 0; i < (int) s.size() && !done; i++) {
        balance += s[i] == '(' ? 1 : -1;
        if (!balance) {
            done = true;
            ans = s.substr(i + 1) + s.substr(0, i + 1);
        }
    }

    if (ans == s) cout << "no\n";
    else cout << ans << "\n";
}