#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong SWAP = 1e12;
const llong REMOVE = 1e12 + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        int zeros = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '0') zeros++;

        int ones = 0, idx = 0;
        llong ans = zeros * REMOVE;

        while (idx < n) {
            while (idx < n && s[idx] == '1') ones++, idx++;

            if (idx < n) {
                ans = min(ans, (--zeros + ones) * REMOVE);
                if (idx && s[idx - 1] == '1')
                    ans = min(ans, SWAP + (zeros + ones - 1) * REMOVE);

                idx++;
            }
        }

        cout << ans << "\n";
    }
}