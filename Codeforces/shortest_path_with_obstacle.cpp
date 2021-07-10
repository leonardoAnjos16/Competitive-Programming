#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int xa, ya, xb, yb, xf, yf;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;

        int ans = abs(xa - xb) + abs(ya - yb);
        if (xa == xb && xb == xf && yf >= min(ya, yb) && yf <= max(ya, yb)) ans += 2;
        else if (ya == yb && yb == yf && xf >= min(xa, xb) && xf <= max(xa, xb)) ans += 2;

        cout << ans << "\n";
    }
}