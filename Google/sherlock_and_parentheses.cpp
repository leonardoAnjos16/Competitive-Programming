#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int L, R;
        cin >> L >> R;

        int pairs = min(L, R);
        long ans = pairs * (pairs + 1LL) / 2LL;
        cout << "Case #" << t << ": " << ans << "\n";
    }
}