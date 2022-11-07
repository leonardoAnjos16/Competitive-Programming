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

        int cnt[2] = {0};
        for (int i = 0; i < n; i++)
            cnt[s[i] - '0']++;

        int aux = 1;
        llong ans = 1LL * cnt[0] * cnt[1];

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) aux++;
            else ans = max(ans, 1LL * aux * aux), aux = 1;
        }

        ans = max(ans, 1LL * aux * aux);
        cout << ans << "\n";
    }
}