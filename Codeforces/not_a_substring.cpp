#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        string ans = "";
        for (int i = 0; i < n; i++)
            ans += "()";

        if (s == "(" || s == ")" || s == "()") cout << "NO\n";
        else if (ans.substr(0, n) != s && ans.substr(1, n) != s) cout << "YES\n" << ans << "\n";
        else cout << "YES\n" << (string(n, '(') + string(n, ')')) << "\n";
    }
}