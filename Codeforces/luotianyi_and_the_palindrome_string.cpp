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

        int l = 0, r = n - 1;
        while (l < r && s[l] == s[r])
            l++, r--;

        if (l < r) cout << n << "\n";
        else if (n <= 2) cout << "-1\n";
        else {
            int idx = 0;
            while (idx < l && s[idx] == s[idx + 1]) idx++;

            if (idx >= l) cout << "-1\n";
            else cout << (n - 1) << "\n";
        }
    }
}