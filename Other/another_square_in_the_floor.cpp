#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int X, Y;
        cin >> X >> Y;

        int ans = max(X, Y) * max(X, Y);
        cout << ans << "\n";
    }
}