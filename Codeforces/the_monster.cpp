#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int i = 0, k = d >= b ? 0 : (b - d + c - 1) / c; i < a; i++, k++)
        if ((d + k * c) % a == b % a) {
            int ans = d + k * c;
            cout << ans << "\n";
            return 0;
        }

    cout << "-1\n";
}