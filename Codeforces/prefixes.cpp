#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for (int i = 1; i < n; i += 2) {
        if (s[i] == s[i - 1]) ans++;
        s[i] = s[i - 1] == 'a' ? 'b' : 'a';
    }

    cout << ans << "\n" << s << "\n";
}