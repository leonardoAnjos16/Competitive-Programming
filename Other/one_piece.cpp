#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 || y1 == y2) cout << "-1\n";
    else {
        long ans = 1LL * abs(x2 - x1) * abs(y2 - y1);
        cout << ans << "\n";
    }
}