#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        string s; cin >> s;

        int ans = a * n;
        if (b >= 0) {
            ans += b * n;
            cout << ans << "\n";
        } else {
            int cnt = 1;
            for (int i = 1; i < n; i++)
                if (s[i] != s[i - 1]) cnt++;

            ans += b * (cnt / 2 + 1);
            cout << ans << "\n";
        }
    }
}