#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        x = max(x - a, 0);
        y = max(y - b, 0);

        if (c >= x + y) cout << "YES\n";
        else cout << "NO\n";
    }
}