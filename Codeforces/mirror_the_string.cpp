#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int idx = 1;
        while (idx < n && s[idx] <= s[idx - 1]) idx++;

        string pref = s.substr(0, idx);

        string rpref = pref;
        reverse(rpref.begin(), rpref.end());

        string ans = pref + rpref;
        ans = min(ans, string(2, s[0]));

        cout << ans << "\n";
    }
}