#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int first = INT_MAX, second = INT_MAX, both = INT_MAX;
        for (int i = 0; i < n; i++) {
            int m; string s;
            cin >> m >> s;

            if (s == "10") first = min(first, m);
            else if (s == "01") second = min(second, m);
            else if (s == "11") both = min(both, m);
        }

        int ans = both;
        if (first < INT_MAX && second < INT_MAX)
            ans = min(ans, first + second);

        if (ans == INT_MAX) cout << "-1\n";
        else cout << ans << "\n";
    }
}