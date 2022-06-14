#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        long X, Y;
        cin >> X >> Y;

        if (!X && !Y) cout << "0\n";
        else if (!X || !Y) cout << "-1\n";
        else {
            if (X > Y)
                swap(X, Y);

            long ans = 0LL;
            while (Y - X > X) {
                ans++;
                X *= 2LL;

                if (X > Y)
                    swap(X, Y);
            }

            ans += 2LL * X - Y + (X < Y);
            ans += 2LL * (Y - X);

            cout << ans << "\n";
        }
    }
}