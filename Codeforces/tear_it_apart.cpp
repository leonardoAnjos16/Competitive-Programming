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

        int ans = INT_MAX;
        for (char c = 'a'; c <= 'z'; c++) {
            int mx = 0, l = 0;
            while (l < n) {
                while (l < n && s[l] == c) l++;

                if (l < n) {
                    int r = l;
                    while (r + 1 < n && s[r + 1] != c) r++;

                    int size = r - l + 1, ops = 0;
                    while (size) {
                        ops++;
                        size /= 2;
                    }

                    mx = max(mx, ops);
                    l = r + 1;
                }
            }

            ans = min(ans, mx);
        }

        cout << ans << "\n";
    }
}