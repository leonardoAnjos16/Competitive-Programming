#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        if (!(n & 1)) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                if (i & 1) cout << "-1";
                else cout << "1";
            }

            cout << "\n";
        } else {
            bool possible = false;
            int half = n / 2, x = -5000;

            while (x <= 5000 && !possible) {
                // half * y + (n - half) * x = x = y
                // (half - 1) * y = x * (half - n + 1)
                // y = x * (half - n + 1) / (half - 1)
                if (half == 1 || (x * (half - n + 1)) % (half - 1)) x++;
                else {
                    int y = x * (half - n + 1) / (half - 1);
                    if (y && abs(y) <= 5000) possible = true;
                    else x++;
                }
            }

            if (!possible) cout << "NO\n";
            else {
                cout << "YES\n";

                int y = x * (half - n + 1) / (half - 1);
                for (int i = 0; i < n; i++) {
                    if (i) cout << " ";
                    if (i & 1) cout << y;
                    else cout << x;
                }

                cout << "\n";
            }
        }
    }
}