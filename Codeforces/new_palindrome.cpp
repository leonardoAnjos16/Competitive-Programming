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

        int l = 1, r = n - 2;
        while (l < r && s[l] == s[0])
            l++, r--;

        cout << (l < r ? "YES" : "NO") << "\n";
    }
}