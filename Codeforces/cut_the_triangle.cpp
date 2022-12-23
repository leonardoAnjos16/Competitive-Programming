#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int x[3], y[3];
        for (int i = 0; i < 3; i++)
            cin >> x[i] >> y[i];

        bool possible = true;
        for (int i = 0; i < 3 && possible; i++) {
            if (x[i] == x[(i + 2) % 3] && y[i] == y[(i + 1) % 3]) possible = false;
            if (x[i] == x[(i + 1) % 3] && y[i] == y[(i + 2) % 3]) possible = false;
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}