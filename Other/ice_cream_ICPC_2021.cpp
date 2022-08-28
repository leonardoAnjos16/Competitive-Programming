#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int X, Y, N;
        cin >> X >> Y >> N;

        int buy = N / (X + Y);
        int ans = 3 * buy * X;

        if (N % (X + Y) >= X) ans += 3 * X;
        else ans += 3 * (N % (X + Y));
        cout << ans << "\n";
    }
}