#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string codeforces = "codeforces";

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        int ans = 0;
        for (int i = 0; i < 10; i++)
            if (s[i] != codeforces[i])
                ans++;

        cout << ans << "\n";
    }
}