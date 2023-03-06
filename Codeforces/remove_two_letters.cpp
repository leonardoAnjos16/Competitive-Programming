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

        int ans = 1;
        for (int i = 2; i < n; i++)
            if (s[i] != s[i - 2]) ans++;

        cout << ans << "\n";
    }
}