#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b) & 1) cout << "-1\n";
    else if ((a + c) & 1) cout << "-1\n";
    else if ((b + c) & 1) cout << "-1\n";
    else if ((!a && !b) || (!a && !c) || (!b && !c)) cout << "-1\n";
    else {
        int d = (a + b) / 2;
        d = min(d, (a + c) / 2);
        d = min(d, (b + c) / 2);

        int x = (a + b) / 2 - d;
        int y = (a + c) / 2 - d;
        int z = (b + c) / 2 - d;

        llong ans = 1LL * x + y + z;
        cout << ans << "\n";
    }
}