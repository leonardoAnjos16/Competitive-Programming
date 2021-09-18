#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long a, b, x, y;
    cin >> a >> b >> x >> y;

    long g = gcd(x, y);
    x /= g; y /= g;

    long ans = min(a / x, b / y);
    cout << ans << "\n";
}