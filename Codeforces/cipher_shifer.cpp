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

        int idx = 0;
        string a = "";

        while (idx < n) {
            a += s[idx++];
            while (idx < n && s[idx] != a.back()) idx++;
            idx++;
        }

        cout << a << "\n";
    }
}