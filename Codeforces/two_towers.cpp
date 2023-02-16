#include <bits/stdc++.h>

using namespace std;

bool alternate(string s) {
    for (int i = 1; i < (int) s.size(); i++)
        if (s[i] == s[i - 1]) return false;

    return true;
}

bool possible(string s, string t, int m) {
    int idx = m - 1;
    while (idx >= 0 && t[idx] != s.back())
        s += t[idx--];

    return alternate(s) && alternate(t.substr(0, idx + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        string s, t;
        cin >> s >> t;

        bool ans = possible(s, t, m) || possible(t, s, n);
        cout << (ans ? "YES" : "NO") << "\n";
    }
}