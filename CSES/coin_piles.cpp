#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        // a - x - 2y = 0
        // b - 2x - y = 0
        // x + 2y = a
        // 2x + y = b
        // -3x = a - 2b
        // 3x = 2b - a
        // x = (2b - a) / 3
        // y = b - 2x

        if (2 * b < a || (2 * b - a) % 3) cout << "NO\n";
        else if (b < 2 * (2 * b - a) / 3) cout << "NO\n";
        else cout << "YES\n";
    }
}