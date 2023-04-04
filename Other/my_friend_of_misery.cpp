#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        llong withdrawn = 0LL, mn = 0LL, mx = 1e18 + 5;
        while (N--) {
            int m; char S;
            cin >> m >> S;

            if (S == '-') mx = min(mx, m + withdrawn + 25LL);
            else mn = max(mn, m + withdrawn + 25LL), withdrawn += m + 25LL;
        }

        llong ans = mx - mn;
        cout << ans << "\n";
    }
}