#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s; cin >> s;

        int lower[MAX] = {0}, upper[MAX] = {0};
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') lower[s[i] - 'a']++;
            else upper[s[i] - 'A']++;
        }

        int ans = 0;
        for (int i = 0; i < MAX; i++) {
            ans += min(lower[i], upper[i]);

            int extra = min(abs(upper[i] - lower[i]) / 2, k);
            ans += extra;
            k -= extra;
        }

        cout << ans << "\n";
    }
}