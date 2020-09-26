#include <bits/stdc++.h>

using namespace std;

long long int mult(int a, int b, int x, int y, int n) {
    int sub = min(a - x, n);
    a -= sub; n -= sub;

    sub = min(b - y, n);
    b -= sub;

    return 1LL * a * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        long long int ans = min(mult(a, b, x, y, n), mult(b, a, y, x, n));
        cout << ans << "\n";
    }
}