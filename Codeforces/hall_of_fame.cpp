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

        bool seen_r = false, seen_l = false, possible = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') seen_r = true;
            else {
                seen_l = true;
                if (seen_r) possible = true;
            }
        }

        if (!seen_r || !seen_l) cout << "-1\n";
        else if (possible) cout << "0\n";
        else {
            int ans = 0;
            while (ans + 1 < n && (s[ans] != 'L' || s[ans + 1] != 'R')) ans++;

            assert(ans + 1 < n);
            cout << (ans + 1) << "\n";
        }
    }
}