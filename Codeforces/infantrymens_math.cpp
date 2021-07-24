#include <bits/stdc++.h>

using namespace std;

#define long long long int

void gcd(long a, long b, long &x, long &y) {
    if (!b) {
        x = 1LL;
        y = 0LL;
    } else {
        gcd(b, a % b, x, y);
        long aux = x; x = y;
        y = aux - a / b * y;
    }
}

long inv(long a, long m) {
    long x, y;
    gcd(a, m, x, y);
    return (x % m + m) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, k; int q;
    cin >> n >> k >> q;

    long inv_mult = inv(k, n);
    while (q--) {
        long c, d;
        cin >> c >> d;

        long idx = (d * inv_mult) % n + 1;
        long ans = c / n + (idx <= c % n);
        cout << ans << "\n";
    }
}