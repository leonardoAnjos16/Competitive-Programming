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

        int ans = 0, idx = 0;
        while (idx < n) {
            int cnt = 1;
            while (idx + 1 < n && s[idx + 1] == s[idx])
                cnt++, idx++;

            idx++;
            ans = max(ans, cnt + 1);
        }

        cout << ans << "\n";
    }
}